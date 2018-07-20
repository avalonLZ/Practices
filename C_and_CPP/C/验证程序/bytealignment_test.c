/*************************************************************************
	> File Name: bytealignment_test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年08月27日 星期日 18时05分59秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma pack(1)
typedef struct
{
    unsigned char head;
    unsigned char cmd;
    unsigned short int len;
    unsigned short int address;
    unsigned char sn;
    unsigned char data[2];
    unsigned char checksum;
    unsigned char end;

}ByteAlignment_t;
//#progma pack()

int main()
{
    unsigned char *tempchar = NULL;
    printf("Bytealignment:%d\r\n", sizeof(ByteAlignment_t));
    
    tempchar = malloc(10);
    printf("%d\r\n", sizeof(tempchar));

}
