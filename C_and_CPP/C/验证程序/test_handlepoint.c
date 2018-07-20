/*************************************************************************
	> File Name: test_handlepoint.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Thu 14 Jun 2018 05:56:37 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define P void*
P ii;
int jj;

void handle1(void)
{
    P i = NULL;
    handle(&i);
    ii = i;
    printf("1i:%x\r\n", i);
    printf("1ii:%x\r\n", ii);
}


void handle(P *point)
{
    *point = (void *)0xabcdef;
}


void ha(void)
{
    int j = 0;
    hand(&j);
    jj = j;
    printf("1j:%d\r\n", j);
    printf("1jj:%d\r\n", jj);
}

void hand(int *point)
{
    *point  = 10;
}

int main(int argc, char *argv[])
{

    
    handle1();
    ha(); 
    printf("2ii:%x\r\n", ii);
    printf("2jj:%d\r\n", jj);
    return 0;
}
