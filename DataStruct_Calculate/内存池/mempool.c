/*************************************************************************
	> File Name: mempool.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Fri 06 Sep 2019 09:28:59 AM PDT
	> Instruction:input: 设计存在问题,不用
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdarg.h>

typedef struct
{
    unsigned int block_total;
    unsigned int block_used;
    unsigned int block_size;
    void *block_addr;
}mp_element_t;

typedef struct
{
    mp_element_t *types;
    unsigned int types_size;
}mp_pool_t;

void mempool_print(mp_pool_t *pool)
{
    int i = 0;

    for(i = 0; i < pool->types_size; ++i)
    {
        printf("这是第%d个分区,包含%d个块,使用了%d个块,每块大小为%d,初始地址为%ld\n", 
                i + 1, pool->types[i].block_total, pool->types[i].block_used, pool->types[i].block_size, pool->types[i].block_addr);
    }
}

mp_pool_t *mempool_init(unsigned int types_size, ...)
{
    int i = 0;
    mp_pool_t *mp = NULL;

    mp = (mp_pool_t *)malloc(sizeof(mp_pool_t));
    
    mp->types_size = types_size;
    mp->types = (mp_element_t *)malloc(sizeof(mp_element_t) * types_size);
    memset(mp->types, 0, sizeof(mp_element_t) * types_size);
    
    va_list val = {0};
    va_start(val, types_size);

    //printf("val = %s\n", *val);

    for(i = 0; i < types_size; ++i)
    {
        int tmp_total = 0;
        int tmp_size = 0;
        tmp_total = va_arg(val, int);
        tmp_size = va_arg(val, int);

        mp->types[i].block_total = tmp_total;
        mp->types[i].block_size = tmp_size;
        mp->types[i].block_addr = malloc(tmp_total * tmp_size);
    }
    va_end(val);

    return mp;
}

void *malloc_mem_from_mp(mp_pool_t *pool, unsigned int need_block, unsigned int signal_block_size)
{
    int i = 0;
    
    for(i = 0; i < pool->types_size; ++i)
    {
        unsigned int remain_block = pool->types[i].block_total - pool->types[i].block_used;
        if(remain_block >= need_block && pool->types[i].block_size == signal_block_size)
        {
            void *tmp_addr = NULL;

            tmp_addr = pool->types[i].block_used * pool->types[i].block_size + pool->types[i].block_addr;
            pool->types[i].block_used += need_block;
            
            return tmp_addr;
        }
        else
            return NULL;
    }
}

void free_mem_to_mp(mp_pool_t *pool, unsigned int need_block, unsigned int signal_block_size)
{
    int i = 0;

    for(i = 0; i < pool->types_size; ++i)
    {
        if(pool->types[i].block_size == signal_block_size && need_block <= pool->types[i].block_used)
        {
            pool->types[i].block_used -= need_block;
        }
    }
}

int main(int argc, char *argv[])
{
    mp_pool_t *mempool = NULL;
    void *addr = NULL;

    mempool = mempool_init(2, 34, 4, 5, 6);

    mempool_print(mempool);

    addr = malloc_mem_from_mp(mempool, 10, 4);
    memset(addr, 1, 40);
    printf("addr is %ld\n", addr);
    
    addr = malloc_mem_from_mp(mempool, 5, 4);
    memset(addr, 2, 4);
    printf("addr is %ld\n", addr);

    free_mem_to_mp(mempool, 5, 4);
    addr = malloc_mem_from_mp(mempool, 1, 4);
    printf("addr is %ld\n", addr);

    return 0;
}
