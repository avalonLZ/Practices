/*************************************************************************
	> File Name: sem.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 17 Dec 2018 07:34:17 PM PST
	> Instruction:子进程结束前使用信号量通知父进程，父进程从而调用wait函数回收子进程（无实际意义）
    一般IPC使用的信号量是System V中的，线程间同步使用的则是Posix（此例程使用System V）
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
    pid_t pid = {0};
    

    //子进程
    if(pid == 0)
    {
        
        return 0;
    }
    else if(pid > 0)
    {
        
        return 0;
    }
    else
    {
        printf("code error\n");
        return 0;
    }
}
