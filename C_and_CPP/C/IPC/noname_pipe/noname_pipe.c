/*************************************************************************
	> File Name: noname_pipe.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月28日 星期二 05时28分05秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    int fd[2];
    char c[10];

    pipe(fd);
    pid = fork();

    if(pid == 0)
    {
        write(fd[1], "hello", strlen("hello")+1);
        printf("fd[1] = %d\n", fd[1]);
        close(fd[1]);//写完马上关闭fd，即不再对此管道进行写操作
        write(fd[1], "world", strlen("world")+1);
        read(fd[0], c, strlen("world")+1);
        wait(0);
        printf("I am fatherprocess,fd[1] = %d,str:%s\n", fd[1],c);//fd[1]值不变但该文件描述符已关闭
        return 0;
    }
    else if(pid > 0)
    {
        read(fd[0], c, strlen("hello")+1);
        //read(fd[0], c, strlen("hello")+1);//此时管道为空子进程将阻塞
        close(fd[0]);
        printf("I am childprocess\n");
        printf("str:%s\n", c);
        _exit(0);
    }
    else
    {
        printf("Fork ChildProcess Fail!\n");
    }
}
