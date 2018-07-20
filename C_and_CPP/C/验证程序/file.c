/*************************************************************************
	> File Name: file.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年03月07日 星期三 03时42分10秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
    FILE * fd;
    fd = fopen("./log.txt", "a+");

    if(fputs("Hello World!\r\n", fd) != EOF)
    {
        printf("Write Success!\r\n");
    }
    else
    {
        printf("Write Faile!\r\n");
    }
    
    return 0;
}
