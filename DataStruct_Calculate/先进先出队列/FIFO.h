/*************************************************************************
	> File Name: FIFO.h
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Mar 2017 12:46:52 AM PST
 ************************************************************************/

#ifndef _FIFO_H
#define _FIFO_H

typedef struct Node
{
    char  data;
    struct Node *next;
}*Pnode;

typedef struct List
{
    Pnode head;
    Pnode end;
    int size;
}*Plist;

#endif
