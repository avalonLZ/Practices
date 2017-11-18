/*************************************************************************
	> File Name: Spinlock.c
	> Author:lizhong
	> Mail: 
	> Created Time: 2017年11月18日 星期六 02时44分07秒
 ************************************************************************/

//单核机，此程序造成了死锁

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/syscall.h>

pthread_spinlock_t spinlock_test;

void *One_Thread(void *tparam)
{
    unsigned char i = 0;
    printf("One_Thread Start!\r\n");
    pthread_spin_lock(&spinlock_test);

    for(i = 0; i <= 5; ++i)
    {
        sleep(1);
        printf("One_Thread i value is:%d\r\n", i);
    }
    pthread_spin_unlock(&spinlock_test);
}

void *Two_Thread(void *tparam)
{
    unsigned char i = 0;
    printf("Two_Thread Start!\r\n");
    pthread_spin_lock(&spinlock_test);

    for(i = 0; i <= 5; ++i)
    {
        sleep(1);
        printf("Two_Thread i value is:%d\r\n", i);
    }
    pthread_spin_unlock(&spinlock_test); 
}

int main(void)
{
    pthread_t one_thread;
    pthread_t two_thread;

    pthread_create(&one_thread, NULL, One_Thread, (void *)0);
    pthread_create(&two_thread, NULL, Two_Thread, (void *)0);

    pthread_join(one_thread, NULL);
    pthread_join(two_thread, NULL);
    printf("ALL END\r\n");
}
