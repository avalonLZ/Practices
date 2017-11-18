/*************************************************************************
	> File Name: ConditionVariable.c
	> Author: lizhong
	> Mail: 
	> Created Time: 2017年11月16日 星期四 05时26分09秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/syscall.h>

pthread_mutex_t mutex_test = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_test = PTHREAD_COND_INITIALIZER;

void *One_Thread(void * tparam)
{
    printf("One_Thread Start!\r\n");
    pthread_mutex_lock(&mutex_test);
    
    //解锁并等待条件变量信号，信号来后立即上锁继续执行该线程
    pthread_cond_wait(&cond_test, &mutex_test);
    printf("One_Thread Receive Signal\r\n");
    pthread_mutex_unlock(&mutex_test);
}

void *Two_Thread(void * tparam)
{
    unsigned char j = 0;

    printf("Two_Thread Start!\r\n");

    for(j = 0; j < 10; ++j)
    {
        if(j == 5)
        {
            printf("Two _Thread Ready Send Signal\r\n");
            
            //发送信号的线程可以不使用互斥锁，根据需求来设计
            pthread_cond_signal(&cond_test);
            printf("Two_Thread Send Signal OK\r\n");
        }
        printf("Two_Thread j Value is:%d\r\n", j);       
    }
    
}

int main(void)
{
    pthread_t one_thread;
    pthread_t two_thread;

    //可能会出现2号线程一直跑，
    //1号线程却还没开始跑的情况，
    //导致1号线程没能收到signal
    pthread_create(&one_thread, NULL, One_Thread, (void *)0);
    sleep(1);//确保1号线程先跑,也可使用SCHED_FIFO或SCHED_RR实时调度算法初始化线程
    pthread_create(&two_thread, NULL, Two_Thread, (void *)0);

    pthread_join(one_thread, NULL);
    pthread_join(two_thread, NULL);
    printf("ALL END\r\n");
}


