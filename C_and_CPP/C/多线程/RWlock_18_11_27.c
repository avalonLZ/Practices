/*************************************************************************
	> File Name: RWlock.c
	> Author:lizhong 
	> Mail: 
	> Created Time: 2017年11月19日 星期日 21时35分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/syscall.h>
#include<time.h>

#define MAX 128

char data[MAX] = "hello world";

pthread_rwlock_t rwlock_test = PTHREAD_RWLOCK_INITIALIZER;

void my_printf(char *s) 
{
    time_t tetime;
    struct tm *t;
    time(&tetime);
    t = gmtime(&tetime);
    printf("%d:%d %s", t->tm_min, t->tm_sec, s);
}

//读者线程
void *Read1_Thread(void *tparam)
{
    char tempdata[MAX] = {0};
    my_printf("Read1_Thread Start!\r\n");
    sleep(3);//等写1上锁
    my_printf("Read1 walk\n");
    pthread_rwlock_rdlock(&rwlock_test);
    my_printf("Read1 lock\n");
    snprintf(tempdata, MAX, "Read1_Thread:%s", data);
    my_printf(tempdata);
    pthread_rwlock_unlock(&rwlock_test);
    my_printf("Read1_Thread End!\r\n");
}

void *Read2_Thread(void *tparam)
{
    char tempdata[MAX] = {0};
    my_printf("Read2_Thread Start!\r\n");
    sleep(3);//等写1上锁
    my_printf("Read2 walk\n");
    pthread_rwlock_rdlock(&rwlock_test);
    my_printf("Read2 lock\n");
    snprintf(tempdata, MAX, "Read2_Thread:%s", data);
    my_printf(tempdata);
    pthread_rwlock_unlock(&rwlock_test);
    my_printf("Read2_Thread End!\r\n");
}

//写者线程
void *Write1_Thread(void *tparam)
{
    my_printf("Write1_Thread Start!\r\n");
    pthread_rwlock_wrlock(&rwlock_test);
    my_printf("Write1 lock\n");
    snprintf(data, MAX, "%s", "hello_read\n");
    sleep(10);
    pthread_rwlock_unlock(&rwlock_test);
    my_printf("Write1_Thread End!\r\n");
}

void *Write2_Thread(void *tparam)
{
    my_printf("Write2_Thread Start!\r\n");
    sleep(5);//等写1上锁
    my_printf("Write2 walk\n");
    pthread_rwlock_wrlock(&rwlock_test);
    my_printf("Write2 lock\n");
    snprintf(data, MAX, "%s", "hello_read\n");
    sleep(10);
    pthread_rwlock_unlock(&rwlock_test);
    my_printf("Write2_Thread End!\r\n");
}
int main(void)
{ 
    pthread_t write1_thread;
    pthread_t read1_thread;
    pthread_t write2_thread;
    pthread_t read2_thread;

    pthread_create(&write1_thread, NULL, Write1_Thread, NULL);
    pthread_create(&read1_thread, NULL, Read1_Thread, NULL);
    pthread_create(&write2_thread, NULL, Write2_Thread, NULL);
    pthread_create(&read2_thread, NULL, Read2_Thread, NULL);

    pthread_join(write1_thread, NULL);
    pthread_join(read1_thread, NULL);
    pthread_join(write2_thread, NULL);
    pthread_join(read2_thread, NULL);
    my_printf("ALL END\r\n");
}

