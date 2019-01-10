/*************************************************************************
	> File Name: word_search.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Thu 10 Jan 2019 12:18:49 AM PST
	> Instruction:查找一篇文章中某单词出现的次数(用拉链法解决are,ear这种问题)
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    char *word;
    unsigned int count;
    struct node *next;
}*Node_t;

typedef struct
{
    Node_t *head;
    Node_t *end;
    unsigned int size;
}List_t;

int main(int argc, char *argv[])
{
    List_t hash[]
    return 0;
}
