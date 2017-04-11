/*************************************************************************
	> File Name: queue.h
	> Author: 
	> Mail: 
	> Created Time: 2017年04月06日 星期四 19时44分53秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

    

template <typename T>
class Queueclass 
{
    private: 
        typedef struct pnode
        {
            T *data;
            struct pnode *front;
            struct pnode *behind;
        }Node;

        typedef struct plist
        {
            Node *head;
            Node *end;
            unsigned long int size;
        }MyList;  
        
        Node *head;
        MyList *queue;

    public:
        Queueclass();
        unsigned long int Input(T temp);
        void Output(T temp);
        ~Queueclass();
} 

#endif
