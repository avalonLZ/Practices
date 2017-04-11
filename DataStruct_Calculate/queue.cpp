/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月06日 星期四 19时44分21秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include "queue.h"
#include<stdlib.h>

using namespace std;

template <typename T>
Queueclass<T>::Queueclass()
{
    queue = new MyList;//C++中需要用new来代替malloc
    queue->head = queue->end = new Node;
    queue->head->data = new T;
    queue->head->data = NULL;
    queue->size = 0;
}

template <typename T>
unsigned long int Queueclass<T>::Input(T temp)
{
    
    return queue->size;
}

template <typename T>
void Queueclass<T>::Output(T temp)
{
    
}

template <typename T>
Queueclass<T>::~Queueclass()
{
    delete(queue->head->data);
    delete(queue->head);
    delete(queue->end);
    delete(queue);
}
