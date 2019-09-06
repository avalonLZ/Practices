/*************************************************************************
	> File Name: mempool.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Fri 06 Sep 2019 09:28:59 AM PDT
	> Instruction:input: 3,1024;2,128;
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    unsigned int type_num;
    unsigned int type_size;
}mp_element_t;

typedef struct
{
    mp_element *type;
}mp_param_t;

void mempool_param_fill()
{
    if(argv[1] == NULL)
    {
        exit(1);
    }
}

void *mempool_init()
{
    return NULL;
}

int main(int argc, char *argv[])
{
    return 0;
}
