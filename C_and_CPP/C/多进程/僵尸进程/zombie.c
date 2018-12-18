/*************************************************************************
	> File Name: zombie.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Mon 17 Dec 2018 05:52:38 PM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
    pid_t pid;

    pid = fork();

    //子进程
    if(pid == 0)
    {
        printf("child end\n");
        return 0;
    }
    else if(pid > 0)
    {
        //子进程退出，父进程不知，父进程又未退出（未被init托管）
        //所以子进程变为僵尸进程，可以使用ps aux | grep 'Z'查看
        //wait();
        printf("father end\n");
        while (1);
        return 0;
    }
}
