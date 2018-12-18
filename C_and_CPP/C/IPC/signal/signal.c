/*************************************************************************
	> File Name: signal.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Mon 17 Dec 2018 06:58:34 PM PST
    > Describe:利用信号，解决子进程僵尸进程问题
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<signal.h>

void Clear_ChildProcess(int sig_num)
{
    wait();
    printf("this process is normal exit\n");
}

int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();
    
    //子进程
    if(pid == 0)
    {
        printf("child run\n");
        sleep(3);
        return 0;
    }
    else if(pid > 0)
    {
        struct sigaction sig = {0};
        sig.sa_handler = &Clear_ChildProcess;
        
        //子进程结束时，会发送SIGCHLD信号，父进程捕捉即可
        sigaction(SIGCHLD, &sig, NULL);

        printf("father run\n");
        while(1);
        
        return 0;
    }
    else
    {
        printf("code error\n");
        return 0;
    }
}
