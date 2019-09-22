/*************************************************************************
	> File Name: mempool_array.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Instruction:
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdarg.h>
#include"mempool_list.h"

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
        mp->mem_pool_node[i].mem_block_list_size = va_arg(val, unsigned int); 
        mp->mem_pool_node[i].mem_block_list.mem_block_size = va_arg(val, unsigned int);

        mp->mem_pool_node[i].mem_block_list.head = malloc(sizeof(mem_block_t));
        memset(mp->mem_pool_node[i].mem_block_list.head, 0, sizeof(mem_block_t));

        mem_block_t *block = NULL;
        block = mp->mem_pool_node[i].mem_block_list.head;

        for(j = 0; j < mp->mem_pool_node[i].mem_block_list_size; ++j)
        {
            block->mem_block_size = mp->mem_pool_node[i].mem_block_list.mem_block_size;
            block->next = block->addr + 
                mp->mem_pool_node[i].mem_block_list.mem_block_size + 
                sizeof(unsigned int) + 
                sizeof(struct node*);
            block = block->next;
        }

        mp->mem_pool_node[i].mem_block_list.mem_block_num =
            mp->mem_pool_node[i].mem_block_list_size;
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
        if(mp->mem_pool_node[i].mem_block_list.mem_block_size != mem_block_size)
            continue;

        if(mp->mem_pool_node[i].mem_block_list.mem_block_num == 0)
            break;

        void *addr = NULL;
        mem_block_t *block = NULL;
            
        addr = mp->mem_pool_node[i].mem_block_list.head->addr;
        block = (mem_block_t *)addr;
        mp->mem_pool_node[i].mem_block_list.head = block->next;
        mp->mem_pool_node[i].mem_block_list.mem_block_num--;
        return addr;
    }

    return NULL;
}

void free_to_mp(mem_pool_t *mp, void *addr)
{
    unsigned int i = 0;
    mem_block_t *block = NULL;

    block = (mem_block_t *)addr;

    for(i = 0; i < mp->mem_pool_node_size; ++i)
    {
        if(mp->mem_pool_node[i].mem_block_list.mem_block_size != block->mem_block_size)
            continue;

        block->next = mp->mem_pool_node[i].mem_block_list.head;
        mp->mem_pool_node[i].mem_block_list.head = block;
        mp->mem_pool_node[i].mem_block_list.mem_block_num++;
    }
}

