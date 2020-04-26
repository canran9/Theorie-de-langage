FROM registry.fit2cloud.com/public/python:v3
WORKDIR /opt/kubeOperator-api

COPY ./requirements /tmp/requirements
RUN cd /tmp/requirements && yum -y install epel-release && yum -y install $(cat rpm_requirements.txt)
RUN cd /tmp/requirements && \
     pip install --upgrade pip setuptools -i https://mirrors.aliyun.com/pypi/simple/ && \
     pip install -r requirements.txt -i https://mirrors.aliyun.com/pypi/simple/ || pip install -r requirements.txt
RUN test -f /root/.ssh/id_rsa || ssh-keygen -f /root/.ssh/id_rsa -t rsa -P ''
RUN echo -e "Host *\n\tStrictHostKeyChecking no\n\tUserKnownHostsFile /dev/null" > /root/.ssh/config
COPY ./requirements/install_terraform.sh /opt/kubeOperator-api
RUN bash /opt/kubeOperator-api/install_terraform.sh
RUN yum -y install crontabs
COPY . /opt/kubeOperator-api
RUN echo > config.yml


ENV LANG=zh_CN.UTF-8
ENV LC_ALL=zh_CN.UTF-8
ENV PYTHONOPTIMIZE=1
ENV C_FORCE_ROOT=1

EXPOSE 8000
ENTRYPOINT ["./entrypoint.sh"]
