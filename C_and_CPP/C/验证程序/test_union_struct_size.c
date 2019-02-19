/*************************************************************************
	> File Name: test_union_struct_size.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Thu 06 Dec 2018 12:18:34 AM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct test
{
    char t_i;
    union{
        char u_a;
        int u_i[3];
        double u_b;
    };
    int t_j;
}test_t;

int main(int argc, char *argv[])
{
    printf("sizeof:%d\n", sizeof(test_t));//32
    return 0;
}
