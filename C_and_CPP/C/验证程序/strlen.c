/*************************************************************************
	> File Name: strlen.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月20日 星期一 18时43分55秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void m(char q[3])
{
    printf("q[3] sizeof is:%d\n", sizeof(q));//同样会退化成地址
}

int main(void)
{
    char *i = "[s1]";
    char qq[3] = {1,2,3};
    m(qq);
    printf("i strlen is %d\r\n", strlen(i));//4
    printf("i sizeof is %d\r\n", sizeof(i));//8
    printf(""" sizeof is %d\n", sizeof(""));//1
    printf("0 sizeof is %d\n", sizeof(0));//4
    printf(""" strlen is %d\n", strlen(""));//0
    printf("0 strlen is %d\n", strlen(0));//core dump
}
