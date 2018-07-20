/*************************************************************************
	> File Name: test_argc_argv.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年03月21日 星期三 19时23分15秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
    int i,j;
    if((i = -1) > 0)
        printf("i > 0\r\n");

    if((i = -1) == 0)
        printf("i == 0;\r\n");

    if((i = -1) < 0)
        printf("i < 0\r\n");

    //////////////////////////////////argc_argv//////////////////////////
    printf("argc = %d\r\n", argc);
    
    for(j = 0;j < argc; ++j)
    {
        printf("argc[%d] = %s\r\n", j, argv[j]);
    }
    return 0;
}
