/*************************************************************************
	> File Name: test_funcpoint.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sun 31 Mar 2019 01:05:29 AM PDT
	> Instruction:
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void my_print1()
{
    printf("my_print1\n");
}

int my_print2(void *parm)
{
    printf("my_print2\n");
    return 0;
}

int main(int argc, char *argv[])
{
    struct
    {
        void (*test1)();
        int (*test2)(void *parm);
    }test;

    test.test1 = my_print1;
    test.test2 = my_print2;

    test.test2(NULL);

    return 0;
}
