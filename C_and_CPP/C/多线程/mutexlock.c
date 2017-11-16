/*************************************************************************
	> File Name: mutexlock.c
	> Author:lizhong 
	> Mail: 
	> Created Time: 2017年11月12日 星期日 06时11分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<sys/syscall.h>
#include<unistd.h>

pthread_mutex_t mutex_test = PTHREAD_MUTEX_INITIALIZER;


pid_t gettid(void)  
{  
  return syscall(__NR_gettid);  
} 

void *Thread_Test(void *main_i)
{
    int *tem_i = main_i;
    
    while(1)
    {
        pthread_mutex_lock(&mutex_test);//创建互斥锁
         
        if(*tem_i < 10)
            (*tem_i)++;    
        else
            break;
        printf("New ThreadID is:%lu, Main_i value is:%d\r\n", (unsigned long int)gettid(),*tem_i);
        pthread_mutex_unlock(&mutex_test);//解锁，从此可以看出，锁实现了一段代码的原子操作，而非只针对某变量的原子操作 
        sleep(1);
    }
    printf("New ThreadID is:%lu, Main_i value is:%d\r\n", (unsigned long int)gettid(),*tem_i);
    pthread_mutex_unlock(&mutex_test);
}

int main(void)
{
    int i = 0;
    int j = 0;
    
    pthread_t threadinfo[3];
    
    for(j = 0; j < 3; ++j)
    {
        pthread_create(&threadinfo[j], NULL, Thread_Test, (void *)&i);
    }

    for(j = 0; j < 3; ++j)
    {
        pthread_join(threadinfo[j], NULL);
    }
    
    printf("All End\r\n");
}
