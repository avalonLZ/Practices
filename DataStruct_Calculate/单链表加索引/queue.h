/*************************************************************************
	> File Name: queue.h
	> Author: 
	> Mail: 
	> Created Time: 2017年04月06日 星期四 19时44分53秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

template <typename T>
class Queueclass 
{
    private: 
        typedef struct pnode
        {
            T *data;
            struct pnode *behind;
            unsigned long int ncount;
        }Node;

        typedef struct plist
        {
            Node *head;
            Node *end;
            unsigned long int count;
        }MyList;  
        
        MyList *queue;

    public:
        Queueclass();
        unsigned long int Input(T *temp);
        T* Output(unsigned long int c);
        ~Queueclass();
}; 

#endif
