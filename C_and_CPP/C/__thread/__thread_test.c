/*************************************************************************
	> File Name: __thread_test.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 24 Dec 2018 11:42:54 PM PST
	> Instruction:
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>

void *ThreadCallBack(void *temp)
{
   static __thread int i = 1;
   printf("Thread is %d i address is 0x%x, value is %d\n", *(int *)temp, &i, i++);
}


int main(int argc, char *argv[])
{
    pthread_t tid = {0};
    unsigned int count = 0;

    for(count = 0; count < 3; ++count)
    {
        pthread_create(&tid, NULL, ThreadCallBack, &count);
        sleep(1);
    }
   

    return 0;
}
