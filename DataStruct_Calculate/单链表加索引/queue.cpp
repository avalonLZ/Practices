/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月06日 星期四 19时44分21秒
 ************************************************************************/
#include<iostream>
#include "queue.h"


using namespace std;

template <typename T>
Queueclass<T>::Queueclass()
{
    queue = (MyList*)malloc(sizeof(MyList));
    queue->head = queue->end = (Node *)malloc(sizeof(Node));
    queue->head->behind = queue->end->behind = NULL; 
    queue->head->data = NULL;
    queue->head->ncount = 0;
    queue->count = 0;
}

template <typename T>
unsigned long int Queueclass<T>::Input(T *temp)
{
    unsigned long int size = 0;
    /*重新分配了一个node所以ncount也从0开始了*/
    queue->end->behind = (Node *)malloc(sizeof(Node));
    queue->end = queue->end->behind;
    queue->end->behind = NULL;
    size = strlen(temp);
    queue->end->data = (T *)malloc(sizeof(T)*(size+1));
    memcpy(queue->end->data, temp, size+1);
    queue->count++; 
    queue->end->ncount = queue->count;
    return queue->end->ncount;
}

template <typename T>
T* Queueclass<T>::Output(unsigned long int c)
{
    Node *tempnode;
    tempnode = queue->head;
    while(tempnode->behind != NULL)
    {
        if(tempnode->ncount != c)
        {
            tempnode = tempnode->behind;
            continue;
        }
        else
        {
            cout << "Find the element!" << endl;
        }
    }
    return tempnode->data;
}

template <typename T>
Queueclass<T>::~Queueclass()
{
    free(queue->head->data);
    free(queue->head);
    free(queue->end);
    free(queue);
}
