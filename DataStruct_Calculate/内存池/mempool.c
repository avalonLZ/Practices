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
#include<stdarg.h>

typedef struct
{
    unsigned int block_num;
    unsigned int block_size;
    void *block;
}mp_element_t;

typedef struct
{
    mp_element_t *type;
    unsigned int size;
}mp_param_t;

void mempool_mem_check()
{

}

void mempool_param_fill(mp_param_t *param, unsigned int type, ...)
{
    int i = 0;
    param->size = type;
    param->type = (mp_element_t *)malloc(sizeof(mp_element_t) * type);
    
    va_list val = {0};
    va_start(val, type);
    printf("val = %d\n", *val);

    for(i = 0; i < type; ++i)
    {
        int tmp_num = 0;
        int tmp_size = 0;
        tmp_num = va_arg(val, int);
        tmp_size = va_arg(val, int);

        param->type[i].block_num = tmp_num;
        param->type[i].block_size = tmp_size;
        param->type[i].block = malloc(tmp_num * tmp_size);
    }
    va_end(val);
}

void *mempool_init(mp_param_t *param)
{
    mempool_param_fill(param, 2, 34, 4, 5, 6);
    return NULL;
}

int main(int argc, char *argv[])
{
    void *mempool = NULL;
    mp_param_t mp_param = {0};

    mempool = mempool_init(&mp_param);
    return 0;
}
