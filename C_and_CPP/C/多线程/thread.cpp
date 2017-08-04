/*************************************************************************
	> File Name: thread.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月10日 星期一 06时36分14秒
 ************************************************************************/

#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;

/*这样写子线程只会运行一次，return后或运行完子线程也就结束了*/
void *FirstThread(void *temp)
{
    while(1)
    {
        sleep(2);
        if(*(unsigned long int *)temp <= 1000)
        (*(unsigned long int *)temp)++;
        cout << "FirstThread:Hello First," << *(unsigned long int *)temp << endl;
    }
    //return NULL;
}

int main()
{
    pthread_t first;
    unsigned long int count = 100;
    pthread_create(&first, NULL, FirstThread, &count);

    while(1)
    {
        sleep(3);
        cout << "MainThread:Hello Main,"<< count  << endl;
    }

    return 0;

}
