/*************************************************************************
	> File Name: point_add.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Thu 12 Sep 2019 06:30:03 AM PDT
	> Instruction:
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv)
{
    char *c = malloc(12);
    int *i = malloc(12);
    void *v = malloc(12);
    printf("c addr:%ld, c + 1 addr:%ld\n", c, c + 1);
    printf("i addr:%ld, i + 1 addr:%ld\n", i, i + 1);
    printf("v addr:%ld, v + 1 addr:%ld, v + sizeof(v):%ld, v + sizeof(void *):%ld\n", 
            v, v + 1, v + sizeof(v), v + sizeof(void *));
    return 0;
}
