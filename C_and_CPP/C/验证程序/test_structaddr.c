/*************************************************************************
	> File Name: test_structaddr.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Mon 12 Nov 2018 07:46:59 PM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    char name[4];
    int age;
}l1_t;

typedef struct
{
    char name[5];
    int sex;
    l1_t l1[0];
}l2_t;

typedef struct
{
    l2_t l2;
    l1_t l1;
}l_t;

int main(int argc, char *argv[])
{
    l_t l;
    printf("l_l1 address is:%x\n", &l.l1);
    printf("l_l2_l1 address is:%x\n", l.l2.l1);
    return 0;
}
