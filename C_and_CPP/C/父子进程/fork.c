/*************************************************************************
	> File Name: fork.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月27日 星期一 05时54分14秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>


unsigned char j;

int main()
{
    pid_t i,k;
    
    i = vfork();
    j++;
    
    if(i == 0)
    {
        /*vfork创建的子进程和父进程共用内存空间*/
        printf("I am a childone process!%d\n", j);
        j = 100;
        _exit(0);
    }
    else
    {
        printf("I am a father process!%d\n", j);
    }
    j = 0;
    k = fork();
    j++;
    if(k == 0)
    {
        /*fork创建的子进程会复制一个父进程的内存空间*/
        //j = 10;
        printf("I am a childtwo process!%d\n", j);
        _exit(0);
    }
    else
    {
        j = 99;
        printf("I am a father process!%d\n", j);
        return 0;
    }
}
