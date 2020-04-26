#!/usr/bin/env bash
BASE_DIR=$(dirname "$0")
source ${BASE_DIR}/utils.sh

function success(){
    echo -e "\033[31m successfully deployed \033[0m"  
}

function start_service(){
    echo "start service......"
    systemctl restart docker.service
    systemctl enable kubeops.service
    systemctl start kubeops.service
}

function main() {
    ${SCRIPTS_DIR}/8_check_install_env.sh
    if [[ $? != 0 ]]; then
        exit 1
    fi
    ${SCRIPTS_DIR}/1_set_iptables.sh
    ${SCRIPTS_DIR}/2_install_docker.sh
    ${SCRIPTS_DIR}/3_prepare_images.sh
    ${SCRIPTS_DIR}/4_copy_data.sh
    start_service
    success
}

main