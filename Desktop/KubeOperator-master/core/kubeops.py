#!/usr/bin/env python3
# coding: utf-8

import os
import subprocess
import threading
import datetime
import logging
import logging.handlers
import psutil
import time
import argparse
import sys
import signal
from collections import defaultdict
import daemon
from daemon import pidfile

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, BASE_DIR)

logging.basicConfig(level=logging.DEBUG, format="%(asctime)s %(message)s", datefmt="%Y-%m-%d %H:%M:%S")

os.environ["PYTHONIOENCODING"] = "UTF-8"
APPS_DIR = os.path.join(BASE_DIR, 'apps')
TMP_DIR = os.path.join(BASE_DIR, 'tmp')
HTTP_HOST = '0.0.0.0'
HTTP_PORT = 8000
WS_PORT = 8002
DEBUG = False
LOG_LEVEL = 'INFO'

START_TIMEOUT = 40
WORKERS = 4
DAEMON = False
LOG_KEEP_DAYS = 7
logging.basicConfig(
    format='%(asctime)s %(message)s', level=logging.INFO,
    datefmt='%Y-%m-%d %H:%M:%S'
)

EXIT_EVENT = threading.Event()
LOCK = threading.Lock()
files_preserve = []
STOP_TIMEOUT = 10

logger = logging.getLogger()

try:
    os.makedirs(TMP_DIR, exist_ok=True)
    os.makedirs(os.path.join(BASE_DIR, "data", "static"), exist_ok=True)
    os.makedirs(os.path.join(BASE_DIR, "data", "media"), exist_ok=True)
except:
    pass


def check_database_connection():
    os.chdir(os.path.join(BASE_DIR, 'apps'))
    for i in range(60):
        logging.info("Check database connection ...")
        code = subprocess.call("python manage.py showmigrations users ", shell=True)
        if code == 0:
            logging.info("Database connect success")
            return
        time.sleep(1)
    logging.info("Connection database failed, exist")
    sys.exit(10)


def make_migrations():
    logging.info("Check database structure change ...")
    os.chdir(os.path.join(BASE_DIR, 'apps'))
    logging.info("Migrate model change to database ...")
    subprocess.call('python3 manage.py migrate', shell=True)


def collect_static():
    logging.info("Collect static files")
    os.chdir(os.path.join(BASE_DIR, 'apps'))
    command = 'python3 manage.py collectstatic --no-input -c &> /dev/null '
    subprocess.call(command, shell=True)
    logging.info("Collect static files done")


def prepare():
    check_database_connection()
    make_migrations()
    collect_static()


def check_pid(pid):
    """ Check For the existence of a unix pid. """
    try:
        os.kill(pid, 0)
    except (OSError, ProcessLookupError):
        return False
    else:
        return True


def get_pid_file_path(s):
    return os.path.join(TMP_DIR, '{}.pid'.format(s))


def get_pid_from_file(path):
    if os.path.isfile(path):
        with open(path) as f:
            try:
                return int(f.read().strip())
            except ValueError:
                return 0
    return 0


def get_pid(s):
    pid_file = get_pid_file_path(s)
    return get_pid_from_file(pid_file)


def is_running(s, unlink=True):
    pid_file = get_pid_file_path(s)

    if os.path.isfile(pid_file):
        pid = get_pid(s)
        if pid == 0:
            return False
        elif check_pid(pid):
            return True

        if unlink:
            os.unlink(pid_file)
    return False


def parse_service(s):
    all_services = [
        'gunicorn', 'celery_ansible', 'celery_default',
        'beat', 'flower', 'daphne',
    ]
    if s == 'all':
        return all_services
    elif s == "web":
        return ['gunicorn', 'flower', 'daphne']
    elif s == 'ws':
        return ['daphne']
    elif s == "task":
        return ["celery_ansible", "celery_default", "beat"]
    elif s == "celery":
        return ["celery_ansible", "celery_default"]
    elif "," in s:
        services = set()
        for i in s.split(','):
            services.update(parse_service(i))
        return services
    else:
        return [s]


def get_start_gunicorn_kwargs():
    print("\n- Start Gunicorn WSGI HTTP Server")
    prepare()
    bind = '{}:{}'.format(HTTP_HOST, HTTP_PORT)
    log_format = '%(h)s %(t)s "%(r)s" %(s)s %(b)s '

    cmd = [
        'gunicorn', 'kubeoperator.wsgi',
        '-b', bind,
        '-k', 'gthread',
        '--threads', '10',
        '-w', str(WORKERS),
        '--max-requests', '4096',
        '--access-logformat', log_format,
        '--access-logfile', '-'
    ]

    if DEBUG:
        cmd.append('--reload')
    return {'cmd': cmd, 'cwd': APPS_DIR}


def get_start_daphne_kwargs():
    print("\n- Start Daphne ASGI WS Server")
    cmd = [
        'daphne', 'kubeoperator.asgi:application',
        '-b', HTTP_HOST,
        '-p', str(WS_PORT),
    ]
    return {'cmd': cmd, 'cwd': APPS_DIR}


def get_start_celery_ansible_kwargs():
    print("\n- Start Celery as Distributed Task Queue: Ansible")
    return get_start_worker_kwargs('ansible', 4)


def get_start_celery_default_kwargs():
    print("\n- Start Celery as Distributed Task Queue: Celery")
    return get_start_worker_kwargs('celery', 2)


def get_start_worker_kwargs(queue, num):
    # Todo: Must set this environment, otherwise not no ansible result return
    os.environ.setdefault('PYTHONOPTIMIZE', '1')
    os.environ.setdefault('ANSIBLE_FORCE_COLOR', 'True')

    if os.getuid() == 0:
        os.environ.setdefault('C_FORCE_ROOT', '1')
    server_hostname = os.environ.get("SERVER_HOSTNAME")
    if not server_hostname:
        server_hostname = '%h'

    cmd = [
        'celery', 'worker',
        '-A', 'celery_api',
        '-l', 'INFO',
        '-c', str(num),
        '-Q', queue,
        '-n', '{}@{}'.format(queue, server_hostname)
    ]
    return {"cmd": cmd, "cwd": APPS_DIR}


def get_start_flower_kwargs():
    print("\n- Start Flower as Task Monitor")
    if os.getuid() == 0:
        os.environ.setdefault('C_FORCE_ROOT', '1')

    cmd = [
        'celery', 'flower',
        '-A', 'celery_api',
        '-l', 'INFO',
        '--url_prefix=flower',
        '--auto_refresh=False',
        '--max_tasks=1000',
        '--tasks_columns=uuid,name,args,state,received,started,runtime,worker'
    ]
    return {"cmd": cmd, "cwd": APPS_DIR}


def get_start_beat_kwargs():
    print("\n- Start Beat as Periodic Task Scheduler")
    os.environ.setdefault('PYTHONOPTIMIZE', '1')
    if os.getuid() == 0:
        os.environ.setdefault('C_FORCE_ROOT', '1')

    scheduler = "django_celery_beat.schedulers:DatabaseScheduler"
    cmd = [
        'celery', 'beat',
        '-A', 'celery_api',
        '-l', 'INFO',
        '--scheduler', scheduler,
        '--max-interval', '60'
    ]
    return {"cmd": cmd, 'cwd': APPS_DIR}


processes = {}


def watch_services():
    max_retry = 3
    services_retry = defaultdict(int)
    stopped_services = {}

    def check_services():
        now = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        for s, p in processes.items():
            print("{} Check service status: {} -> ".format(now, s), end='')
            try:
                p.wait(timeout=1)
            except subprocess.TimeoutExpired:
                pass
            ok = is_running(s)
            if not ok:
                stopped_services[s] = ''
                print("stopped with code: {}({})".format(p.returncode, p.pid))
            else:
                print("running at {}".format(p.pid))
                stopped_services.pop(s, None)
                services_retry.pop(s, None)

    def retry_start_stopped_services():
        for s in stopped_services:
            if services_retry[s] > max_retry:
                logging.info("Service start failed, exit: ", s)
                EXIT_EVENT.set()
                break

            p = start_service(s)
            logging.info("> Find {} stopped, retry {}, {}".format(
                s, services_retry[s] + 1, p.pid)
            )
            processes[s] = p
            services_retry[s] += 1

    while not EXIT_EVENT.is_set():
        try:
            with LOCK:
                check_services()
            retry_start_stopped_services()
            time.sleep(30)
        except KeyboardInterrupt:
            print("Start stop service")
            time.sleep(1)
            break
    clean_up()


def start_service(s):
    services_kwargs = {
        "gunicorn": get_start_gunicorn_kwargs,
        "celery_ansible": get_start_celery_ansible_kwargs,
        "celery_default": get_start_celery_default_kwargs,
        "beat": get_start_beat_kwargs,
        "flower": get_start_flower_kwargs,
        "daphne": get_start_daphne_kwargs,
    }

    kwargs = services_kwargs.get(s)()
    pid_file = get_pid_file_path(s)

    if os.path.isfile(pid_file):
        os.unlink(pid_file)
    cmd = kwargs.pop('cmd')
    p = subprocess.Popen(cmd, **kwargs)
    with open(pid_file, 'w') as f:
        f.write(str(p.pid))
    return p


def start_services_and_watch(s):
    logging.info(time.ctime())
    logging.info('Kubeoperator version {}, more see https://www.kubeoperator.io')

    services_set = parse_service(s)
    for i in services_set:
        if is_running(i):
            show_service_status(i)
            continue
        p = start_service(i)
        time.sleep(2)
        processes[i] = p

    if not DAEMON:
        watch_services()
    else:
        show_service_status(s)
        context = get_daemon_context()
        with context:
            watch_services()


def get_daemon_context():
    daemon_pid_file = get_pid_file_path('jms')
    context = daemon.DaemonContext(
        pidfile=pidfile.TimeoutPIDLockFile(daemon_pid_file),
        signal_map={
            signal.SIGTERM: lambda x, y: clean_up(),
            signal.SIGHUP: 'terminate',
        },
        files_preserve=files_preserve,
        detach_process=True,
    )
    return context


def stop_service(srv, sig=15):
    services_set = parse_service(srv)
    for s in services_set:
        if not is_running(s):
            show_service_status(s)
            continue
        print("Stop service: {}".format(s), end='')
        pid = get_pid(s)
        os.kill(pid, sig)
        with LOCK:
            process = processes.pop(s, None)
        if process is None:
            try:
                process = psutil.Process(pid)
            except:
                pass
        if process is None:
            print("\033[31m No process found\033[0m")
            continue
        try:
            process.wait(1)
        except:
            pass
        for i in range(STOP_TIMEOUT):
            if i == STOP_TIMEOUT - 1:
                print("\033[31m Error\033[0m")
            if not is_running(s):
                print("\033[32m Ok\033[0m")
                break
            else:
                time.sleep(1)
                continue

    if srv == "all":
        stop_daemon_service()


def stop_daemon_service():
    pid = get_pid('jms')
    if pid and check_pid(pid):
        os.kill(pid, 15)


def stop_multi_services(services):
    for s in services:
        stop_service(s, sig=9)


def stop_service_force(s):
    stop_service(s, sig=9)


def clean_up():
    if not EXIT_EVENT.is_set():
        EXIT_EVENT.set()
    processes_dump = {k: v for k, v in processes.items()}
    for s1, p1 in processes_dump.items():
        stop_service(s1)
        p1.wait()


def show_service_status(s):
    services_set = parse_service(s)
    for ns in services_set:
        if is_running(ns):
            pid = get_pid(ns)
            print("{} is running: {}".format(ns, pid))
        else:
            print("{} is stopped".format(ns))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description="""
        Kubeoperator service control tools;
        Example: \r\n
        %(prog)s start all -d;
        """
    )
    parser.add_argument(
        'action', type=str,
        choices=("start", "stop", "restart", "status"),
        help="Action to run"
    )
    parser.add_argument(
        "service", type=str, default="all", nargs="?",
        choices=("all", "web", "task", "gunicorn", "celery", "beat", "celery,beat", "flower", "ws"),
        help="The service to start",
    )
    parser.add_argument('-d', '--daemon', nargs="?", const=1)
    parser.add_argument('-w', '--worker', type=int, nargs="?", const=4)
    parser.add_argument('-f', '--force', nargs="?", const=1)
    args = parser.parse_args()
    if args.daemon:
        DAEMON = True

    if args.worker:
        WORKERS = args.worker

    action = args.action
    srv = args.service

    if action == "start":
        start_services_and_watch(srv)
        os._exit(0)
    elif action == "stop":
        print("Stop service")
        if args.force:
            stop_service_force(srv)
        else:
            stop_service(srv)
    elif action == "restart":
        DAEMON = True
        stop_service(srv)
        time.sleep(5)
        start_services_and_watch(srv)
    else:
        show_service_status(srv)
