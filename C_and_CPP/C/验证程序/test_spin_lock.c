/*************************************************************************
	> File Name: test_spin_lock.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Fri 03 Aug 2018 08:25:22 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#include<unistd.h>

static pthread_spinlock_t sp_lock;

void *pthreadone(void *p)
{
    unsigned long int i = 0;
    printf("threadone start spin\r\n");
    pthread_spin_lock(&sp_lock);
    while (++i < 999999999 ? 1 : 0)
        printf("one\r\n");
    pthread_spin_unlock(&sp_lock);
    printf("threadone end spin\r\n");
}

void *pthreadthree(void *p)
{
    unsigned long int i = 0;
    printf("threadthree start spin\r\n");
    pthread_spin_lock(&sp_lock);
    while (++i < 999999999 ? 1 : 0)
        printf("three\r\n");
    pthread_spin_unlock(&sp_lock);
    printf("threadthree end spin\r\n");
}

void *pthreadtwo(void *p)
{
    unsigned long int i = 0;
    printf("threadtwo start spin\r\n");
    pthread_spin_lock(&sp_lock);
    while (++i < 999999999 ? 1 : 0)
        printf("two\r\n");
    pthread_spin_unlock(&sp_lock);
    printf("threadtwo end spin\r\n");
}

int main(int argc, char *argv[])
{
    pthread_t toneid = 0;
    pthread_t ttwoid = 0;
    void *onerst;
    void *tworst;
    pthread_spin_init(&sp_lock, 0);
    pthread_create(&toneid, NULL, pthreadone, NULL);
    pthread_setname_np(toneid, "thread_one");
    pthread_create(&ttwoid, NULL, pthreadtwo, NULL);
    pthread_setname_np(ttwoid, "thread_two");
    pthread_join(toneid, &onerst);
    printf("thread one end\r\n");
    pthread_join(ttwoid, &tworst);
    printf("thread two end\r\n");
    pthread_spin_destroy(&sp_lock);
    return 0;
}
