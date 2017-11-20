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

#define MAXDATASIZE 1024

typedef struct
{
    unsigned char flag_hasdata;//防止读者线程先运行时读数据
    char data[MAXDATASIZE]; 
}Data_t;

pthread_rwlock_t rwlock_test = PTHREAD_RWLOCK_INITIALIZER;

//读者线程
void *One_Thread(void *tparam)
{
     Data_t *pdata = tparam;
    printf("One_Thread Start!\r\n");

    while(1)
    {
        pthread_rwlock_rdlock(&rwlock_test);

        if(pdata->flag_hasdata == 1)
        {
            printf("One_Thread has rev data:%s", pdata->data);//stdin中的数据自带换行
            break;   
        }
        pthread_rwlock_unlock(&rwlock_test);
    }
    printf("One_Thread End!\r\n");
}

//写者线程
void *Two_Thread(void *tparam)
{
    Data_t *pdata = tparam;
    printf("Two_Thread Start!,Please input data!\r\n");

    while(1)
    {
        pthread_rwlock_wrlock(&rwlock_test);
        pdata->flag_hasdata = 0;
        fgets(pdata->data, MAXDATASIZE, stdin);
        printf("Two_Thread has rev Data!\r\n");
        pdata->flag_hasdata = 1;
        pthread_rwlock_unlock(&rwlock_test);
        break;
    }
    printf("Two_Thread End!\r\n");
}

int main(void)
{ 
    pthread_t one_thread;
    pthread_t two_thread;
    Data_t tdata = {0};

    pthread_create(&one_thread, NULL, One_Thread, (void *)&tdata);
    sleep(1);
    pthread_create(&two_thread, NULL, Two_Thread, (void *)&tdata);

    pthread_join(one_thread, NULL);
    pthread_join(two_thread, NULL);
    printf("ALL END\r\n");
}

