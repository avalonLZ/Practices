/*************************************************************************
	> File Name: Sem.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月19日 星期日 00时44分58秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/syscall.h>
#include<semaphore.h>

sem_t sem_test;

void *One_Thread(void *tparam)
{
    printf("One_Thread is Start!\r\n");
    sem_wait(&sem_test);
    printf("One_Thread received sem\r\n");
    printf("One_Thread End!\r\n");
}

void *Two_Thread(void *tparam)
{
    unsigned char i = 0;
    printf("Two_Thread is Start!\r\n");

    for(i = 0; i <= 5; ++i)
    {
        sleep(1);
        printf("Two_Thread i value is:%d\r\n", i);
    }
    sem_post(&sem_test);
    printf("Two_Thread End!\r\n");
}

int main(void)
{
    pthread_t one_thread;
    pthread_t two_thread;

    sem_init(&sem_test, 0, 0);

    pthread_create(&one_thread, NULL, One_Thread, (void *)0);
    pthread_create(&two_thread, NULL, Two_Thread, (void *)0);

    pthread_join(one_thread, NULL);
    pthread_join(two_thread, NULL);

    printf("All End\r\n");
}

