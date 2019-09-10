/*************************************************************************
	> File Name: mempool_u.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 09 Sep 2019 06:33:07 PM PDT
	> Instruction:
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"mempool_array.h"


int main(int argc, char *argv[])
{
    int *addr = NULL;
    mem_pool_t *mp = NULL;
    mp = mem_pool_init(2, 3, sizeof(int), 5, sizeof(char));


    addr = (int *)malloc_from_mp(mp, sizeof(int));
    printf("addr = %ld\n", addr);
    free_to_mp(addr);
    printf("addr = %ld\n", addr);
    addr = (int *)malloc_from_mp(mp, sizeof(int));
    printf("addr = %ld\n", addr);
    return 0;
}
