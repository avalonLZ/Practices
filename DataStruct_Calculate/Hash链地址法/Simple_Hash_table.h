/*************************************************************************
	> File Name: Simple_Hash_table.h
	> Author: 
	> Mail: 
	> Created Time: Tue 14 Mar 2017 01:35:08 AM PDT
 ************************************************************************/

#ifndef _SIMPLE_HASH_TABLE_H
#define _SIMPLE_HASH_TABLE_H

#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

typedef struct node
{
    char *data;
    struct node *behind;
}Hnode;

class HashList
{
    private:
        Hnode *list[25];

    public:
        HashList();
        void DataInput(const char *data);
        string DataOutput(const char *temp);

};

#endif
