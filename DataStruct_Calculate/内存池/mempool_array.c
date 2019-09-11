/*************************************************************************
	> File Name: mempool_array.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 09 Sep 2019 06:34:04 PM PDT
	> Instruction:
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdarg.h>
#include"mempool_array.h"

mem_pool_t *mem_pool_init(unsigned int types, ...)
{
    int i = 0;
    int j = 0;
    mem_pool_t *mp = NULL;
   
    mp = (mem_pool_t *)malloc(sizeof(mem_pool_t));

    if(mp == NULL)
        return NULL;

    memset(mp, 0, sizeof(mem_pool_t));
    mp->mem_pool_node_size = types;

    mp->mem_pool_node = (mem_pool_node_t *)malloc(sizeof(mem_pool_node_t) * types);

    if(mp->mem_pool_node == NULL)
    {
        free(mp);
        return NULL;
    }
    memset(mp->mem_pool_node, 0, sizeof(mem_pool_node_t) * types);

    va_list val = {0};
    va_start(val, types);

    for(i = 0; i < types; ++i)
    {
        unsigned int mem_block_array_size = 0; 
        unsigned int mem_block_size = 0; 
        
        mem_block_array_size = va_arg(val, unsigned int); 
        mem_block_size = va_arg(val, unsigned int);

        mp->mem_pool_node[i].mem_block_array = (mem_block_t *)malloc(sizeof(mem_block_t) * mem_block_array_size); 
        
        if(mp->mem_pool_node[i].mem_block_array == NULL)
        {
            free(mp->mem_pool_node);
            free(mp);
            va_end(val);
            return NULL;
        }
        
        memset(mp->mem_pool_node[i].mem_block_array, 0, sizeof(mem_block_t) * mem_block_array_size);
        mp->mem_pool_node[i].mem_block_array_size = mem_block_array_size; 
        mp->mem_pool_node[i].mem_block_size = mem_block_size;

        for(j = 0; j < mem_block_array_size; ++j)
        {
            mp->mem_pool_node[i].mem_block_array[j].addr = malloc(mem_block_size);
            printf("addr:%ld\n", mp->mem_pool_node[i].mem_block_array[j].addr);
        }
    }

    va_end(val);
    return mp;
}

void *malloc_from_mp(mem_pool_t *mp, unsigned int mem_block_size)
{
    int i = 0;
    int j = 0;

    for(i = 0; i < mp->mem_pool_node_size; ++i)
    {
        if(mp->mem_pool_node[i].mem_block_size == mem_block_size)
        {
            for(j = 0; j < mp->mem_pool_node[i].mem_block_array_size; ++j)
            {
                if(mp->mem_pool_node[i].mem_block_array[j].flag.used == 0)
                {
                    mp->mem_pool_node[i].mem_block_array[j].flag.used = 1;
                    printf("addr:%ld, flag set 1 addr:%ld\n", &mp->mem_pool_node[i].mem_block_array[j].addr, &mp->mem_pool_node[i].mem_block_array[j].flag);
                    return mp->mem_pool_node[i].mem_block_array[j].addr;
                }
            }
        }
    }
    return NULL;
}

void free_to_mp(mem_pool_t *mp, void *addr)
{
    int i = 0;
    int j = 0;

    for(i = 0; i < mp->mem_pool_node_size; ++i)
    {
        for(j = 0; j < mp->mem_pool_node[i].mem_block_array_size; ++j)
        {
            if(mp->mem_pool_node[i].mem_block_array[j].flag.used == 1)
            {
                mp->mem_pool_node[i].mem_block_array[j].flag.used = 0;
                return;
            }
        }
    }
}


