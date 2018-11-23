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
    //unsigned char z;
    //注意，此处依然j依然会被gcc编译器对齐
    unsigned int i;
    unsigned char j;
    
}TestSize_t;


int main(void)
{
    TestSize_t test;
    printf("sizeof:%d\n", sizeof(unsigned int));
    printf("sizeof(test)Size is:%d\r\n", sizeof(test));
    printf("sizeof(TestSize_t)Size is:%d\r\n", sizeof(TestSize_t));
}
