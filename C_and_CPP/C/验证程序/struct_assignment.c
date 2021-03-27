/*************************************************************************
	> File Name: struct_assignment.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月21日 星期二 07时00分47秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 10

typedef struct
{
    char strs[MAX_SIZE];
    int i;
    unsigned char ii;

}Test_t;


int main(void)
{
    //直接填0可以将结构体中所有变量初值都至为0
    //包括数组
    Test_t t1;//= {0};
    t1.i = 100;
    Test_t t2;
    int i = 0;

    t2 = t1;
    printf("%d\r\n", t2.i);

    for (i = 0; i < MAX_SIZE; ++i)
        printf("***i:%d*****%d*****\n", i, t2.strs[i]);
}
