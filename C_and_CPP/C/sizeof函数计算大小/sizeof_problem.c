/*************************************************************************
	> File Name: sizeof_problem.c
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Mar 2017 12:39:19 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>


int main()
{
    /*sizeof 就算都是0也会如实计算出数据所占内存空间的大小*/
    unsigned char i[100] = {0};
    int j[100] = {0};
    int len = 0;
    len = sizeof(i);
    printf("The char_array's len is:%d\n", len);
    len = sizeof(j);
    printf("The int_array's len is:%d\n", len);
    return 0;
}
