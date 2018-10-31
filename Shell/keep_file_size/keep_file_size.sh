#!/bin/bash

#File Name: keep_file_size.sh
#Author:lizhong
#Mail:423810942@qq.com
#Created Time: Fri 10 Aug 2018 08:47:59 PM PDT
#Instruction:指定某文件达到一定大小后重命名，再新建一个文件（配合内存泄漏检测宏使用):./keep_file_size.sh /home/lz/Desktop/xxx.txt

function keep_file()
{
    date_info=$(date '+%Y-%m-%d_%H:%M:%S')    
    dir=$1

    #匹配出文件名
    files_name=${dir##*/}

    #匹配出文件夹路径
    files_dir=${dir%/*}

    mv ${dir} ${files_dir}"/"${date_info}"_"${files_name}
    touch ${dir}
}

function keep_file_size()
{
    file_size=`ls -l $1 | awk '{print $5}'`
    
    #>10K
    if [ ${file_size} -gt 10000 ]
    then
        keep_file $1
    fi
}

#######################################main############################################

while true
do
    keep_file_size $1
    sleep 3
done


