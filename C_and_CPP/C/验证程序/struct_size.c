/*************************************************************************
	> File Name: struct_size.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 00时29分32秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    unsigned char z;
    //unsigned long int i;
    //unsigned char j;
    
}TestSize_t;


int main(void)
{
    TestSize_t test;
    printf("sizeof(test)Size is:%d\r\n", sizeof(test));
    printf("sizeof(TestSize_t)Size is:%d\r\n", sizeof(TestSize_t));
}
