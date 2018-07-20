/*************************************************************************
	> File Name: sizeof_test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月26日 星期二 23时43分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    /*
    unsigned char *i = malloc(sizeof(unsigned int));
    *(unsigned int *)i = 65543;
    printf("%d\n\r", sizeof(*i));//结果为1
    */
    char *temstr[] = {"li"};
    
    printf("%d\n\r", sizeof(temstr));
}
