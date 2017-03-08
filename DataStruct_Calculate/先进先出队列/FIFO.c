/*************************************************************************
	> File Name: FIFO.c
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Mar 2017 12:28:01 AM PST
 ************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include"FIFO.h"

Plist UseList;
static int ListSize = 1;

void Createlist()
{
    UseList = malloc(sizeof(struct Node));
    UseList->head = UseList->end = malloc(sizeof(struct Node));
    UseList->head->data = 'a';
    UseList->head->next = NULL;
    UseList->size = ListSize;
}

void AddNodeToList()
{
    static char i = 'a';
    i++;
    ListSize++;
    UseList->end->next = malloc(sizeof(struct Node));
    UseList->end = UseList->end->next;
    UseList->end->data = i;
    UseList->end->next = NULL;
    UseList->size = ListSize;
}

char SubNodeFromList()
{
    char data;
    Pnode p;
    data = UseList->head->data;
    p = UseList->head->next;
    free(UseList->head);
    UseList->head = p;
    return data;
}

int main()
{
    unsigned char i;
    char c;
    Createlist();

    for(i = 0; i < 6; i++)
    {
        AddNodeToList();
        printf("%c\n",UseList->end->data);
    } 
    printf("**********************************************************");
    for(i = 0; i < 7; i++)
    {
        c = SubNodeFromList();
        printf("%c\n", c);
    }   
    return 0;
}
