#!/bin/bash

#File Name: check_resource.sh
#Author:lizhong
#Mail:423810942@qq.com
#Created Time: Fri 20 Jul 2018 12:34:00 AM PDT
#Instruction:
#获取系统相关资源数据，以天为单位，自动保存（暂不使用超出大小自动迭代功能）

LOG_FILES_GENBASE_DIR=/var
LOG_FILES_BASE_DIR=/var/log
LOG_FILES_DIR=/var/log/qos_log
LOG_FILE_DIR=/var/log/qos_log/check.log

#function clean_log_file()
#{
#    sed -i '1,17d' ${LOG_FILE_DIR}
#}
#
#function keep_log_file_size()
#{
#    log_file_size=`ls -l ${LOG_FILE_DIR} | awk '{print $5}'`
#    #echo `expr ${log_file_size} / 1000`
#    
#    #>1M 10min,
#    if [ ${log_file_size} -gt 1000000 ]
#    then
#        clean_log_file
#    fi
#}

function check_file()
{
    if [ ! -d "${LOG_FILES_GENBASE_DIR}" ]
    then
        mkdir ${LOG_FILES_GENBASE_DIR}
    fi

    if [ ! -d "${LOG_FILES_BASE_DIR}" ]
    then
        mkdir ${LOG_FILES_BASE_DIR}
    fi

    if [ ! -d "${LOG_FILES_DIR}" ]
    then
        mkdir ${LOG_FILES_DIR}
    fi

    if [ ! -f "${LOG_FILE_DIR}" ]
    then
        touch ${LOG_FILE_DIR}
    fi
}

function date_info()
{
    date_info=$(date '+%Y-%m-%d %H:%M:%S')
    
    if [ "${1}"x = "print"x ]
    then
        echo ${date_info}
    elif [ "${1}"x = "save"x ]
    then
        echo ${date_info} >> ${LOG_FILE_DIR}
    elif [ "${1}"x = "sync"x ]
    then    
        today=$(echo ${date_info} | awk '{print $1}')
        old_today=${today}
    elif [ "${1}"x = "check"x ]
    then    
        today=$(echo ${date_info} | awk '{print $1}')
        
        if [ ! "${today}"x = "${old_today}"x ]
        then
            mv ${LOG_FILE_DIR} ${LOG_FILES_DIR}"/"${old_today}"_check.log"
            touch ${LOG_FILE_DIR}
        fi

        old_today=${today}
    fi
}

function init()
{
    check_file
    date_info "sync"
}

function get_memory_info()
{
	sync && echo 3 > /proc/sys/vm/drop_caches
    
    memory_info=$(free -m)
    memory_free="memory_free:"$(echo ${memory_info} | awk '{print $17}')
    
    if [ "${1}"x = "print"x ]
    then
        echo ${memory_free}
    elif [ "${1}"x = "save"x ]
    then
        echo ${memory_free} >> ${LOG_FILE_DIR}
    fi
}

function get_thread_info()
{
    if [ "${1}"x = "print"x ]
    then
        echo "$(top -b -H -n 1 | sed -n '7,27p')"
    elif [ "${1}"x = "save"x ]
    then
	echo "$(top -b -H -n 1 | sed -n '7,27p')" >> ${LOG_FILE_DIR}
    fi
}

function get_connect_info()
{
    connect_info=$(cat /proc/sys/net/netfilter/nf_conntrack_count | awk '{printf $1}')
    connect_count="connect_count:"${connect_info}

    if [ "${1}"x = "print"x ]
    then
        echo ${connect_count}
    elif [ "${1}"x = "save"x ]
    then
        echo ${connect_count} >> ${LOG_FILE_DIR}
    fi
}

function get_disk_info()
{
    disk_info=$(df -m)
    disk_used="disk_used:"$(echo ${disk_info} | awk '{print $10}')
    disk_free="disk_free:"$(echo ${disk_info} | awk '{print $11}')
    disk_pused="disk_pused:"$(echo ${disk_info} | awk '{print $12}')
    
    if [ "${1}"x = "print"x ]
    then
        echo ${disk_used}, ${disk_free}, ${disk_pused}
    elif [ "${1}"x = "save"x ]
    then
        echo ${disk_used}, ${disk_free}, ${disk_pused} >> ${LOG_FILE_DIR}
    fi
}

function run()
{	
    date_info "check"
    date_info "print"
    date_info "save"

    get_memory_info "print"
    get_memory_info "save"
    
    get_connect_info "print"
    get_connect_info "save"
    
    get_disk_info "print"
    get_disk_info "save"
    
    get_thread_info "print"
    get_thread_info "save"
	
    echo "" >> ${LOG_FILE_DIR} 
    echo ""
}

#######################################main############################################

init

while true
do
    run
    sleep 300
done


