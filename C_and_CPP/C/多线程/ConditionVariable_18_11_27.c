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
#include<time.h>

pthread_mutex_t mutex_test = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_test = PTHREAD_COND_INITIALIZER;

void my_printf(char *s) 
{
    time_t tetime;
    struct tm *t;
    time(&tetime);
    t = gmtime(&tetime);
    printf("%d:%d %s", t->tm_min, t->tm_sec, s);
}

void *One_Thread(void * tparam)
{
    my_printf("One_Thread Start!\r\n");

    pthread_mutex_lock(&mutex_test);
    my_printf("One lock，sleep 1s!\n");
    sleep(1);//1号线程上锁后，2号线程将无法取得锁，
    
    my_printf("One_Thread  unlock and wait signal!\r\n");
    pthread_cond_wait(&cond_test, &mutex_test);
    my_printf("One_Thread Receive Signal\r\n");
    //由于此线程上锁，所以线程2无法执行
    my_printf("One_Thread run\n");
    
    sleep(3);
    my_printf("One_Thread unlock\n");
    pthread_mutex_unlock(&mutex_test);
}

void *Two_Thread(void * tparam)
{
    my_printf("Two_Thread Start!\r\n");

    pthread_mutex_lock(&mutex_test);
    my_printf("Two lock，sleep 1s!\n");
    sleep(1);//2号线程上锁后，1号线程将无法取得锁
    
    my_printf("Two_Thread  unlock and wait signal!\r\n");
    pthread_cond_wait(&cond_test, &mutex_test);
    my_printf("Two_Thread Receive Signal\r\n");
    //由于此线程上锁，所以线程1无法执行
    my_printf("Two_Thread run\n");
    
    sleep(3);
    my_printf("Two_Thread unlock\n");
    pthread_mutex_unlock(&mutex_test);
}

void *Signal_Thread(void * tparam)
{
    unsigned char j = 0;

    my_printf("Signal_Thread Start!\r\n");

    //睡觉，保证线程1和2都已经进入了等待
    sleep(5);

    my_printf("Signal _Thread Ready Send Signal\r\n");
    pthread_cond_broadcast(&cond_test);//广播后，所有等待线程都将收到信号，继续执行
    my_printf("Signal_Thread Send Signal OK\r\n");
}

int main(int argc, char *argv[])
{
    pthread_t one_thread;
    pthread_t two_thread;
    pthread_t signal_thread;
    
    pthread_create(&one_thread, NULL, One_Thread, (void *)0);
    pthread_create(&two_thread, NULL, Two_Thread, (void *)0);
    pthread_create(&signal_thread, NULL, Signal_Thread, (void *)0);

    pthread_join(one_thread, NULL);
    pthread_join(two_thread, NULL);
    pthread_join(signal_thread, NULL);
    my_printf("ALL END\r\n");
    return 0;
}


