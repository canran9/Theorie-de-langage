BASE_DIR=$(cd "$(dirname "$0")";pwd)
source ${BASE_DIR}/scripts/utils.sh
PROJECT_DIR=${BASE_DIR}
SCRIPT_DIR=${BASE_DIR}/scripts
action=$1
target=$2
args=$@


function usage() {
   echo "deploy install script"
   echo
   echo "Usage: "
   echo "  kubeopsctl [COMMAND] [ARGS...]"
   echo "  kubeopsctl --help"
   echo
   echo "Commands: "
   echo "  install "
   echo "  start "
   echo "  uninstall "
   echo "  upgrade "
   echo "  restart [service] "
   echo "  reload [service] "
   echo "  status "
   echo "  down [service] "
   echo "  python enter api, run python manage.py shell"
   echo "  db connect database"
   echo "  ... other commmands executed by docker-compose such as logs, etc."
}


function service_to_docker_name() {
    service=$1
    if [[ "${service:0:3}" != "f2o" ]];then
        service=jms_${service}
    fi
    echo ${service}
}

function main() {
    EXE='docker-compose -f /opt/kubeoperator/docker-compose.yml'
    case "${action}" in
      install)
         bash ${SCRIPT_DIR}/5_install.sh
         ;;
      uninstall)
         bash ${SCRIPT_DIR}/6_uninstall.sh
         ;;
      upgrade)
         bash ${SCRIPT_DIR}/7_upgrade.sh
         ;;
      start)
         ${EXE} up -d
         ;;
      restart)
         ${EXE} restart ${target}
         ;;
      reload)
         ${EXE} up -d &> /dev/null
         ${EXE} restart ${target}
         ;;
      status)
         ${EXE} ps
         ;;
      down)
         if [[ -z "${target}" ]];then
             ${EXE} down
         else
             ${EXE} stop ${target} && ${EXE} rm ${target}
         fi
         ;;
      tail)
          if [[ -z "${target}" ]];then
              ${EXE} logs --tail 100 -f
          else
              docker_name=$(service_to_docker_name ${target})
              docker logs -f ${docker_name} --tail 100
          fi
          ;;
      python)
          docker exec -it kubeops_api python manage.py shell
          ;;
      db)
          docker exec -it kubeops_api python manage.py dbshell
          ;;
      exec)
          docker_name=$(service_to_docker_name ${target})
          docker exec -it ${docker_name} sh
          ;;
      help)
         usage
         ;;
      --help)
         usage
         ;;
      *)
         ${EXE} ${args}
    esac
}

main

