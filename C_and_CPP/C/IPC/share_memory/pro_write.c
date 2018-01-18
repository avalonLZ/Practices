/*************************************************************************
	> File Name: pro_write.c
	> Author: 
	> Mail: 
	> Created Time: 2018年01月03日 星期三 18时03分27秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/shm.h>

#define HELLO "Hello World!"

int ShareMemory_Init(key_t temkey, unsigned long int size)
{
    return shmget(temkey, size, 0666);
}

int main()
{
    int shmid = 0;

    shmid = ShareMemory_Init(strlen(HELLO));
    shmat(shmid, );
    
}
