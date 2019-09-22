/*************************************************************************
	> File Name: mempool_array.h
	> Author:lizhong
	> Mail:423810942@qq.com
	> Instruction:
 ************************************************************************/
#ifndef _MEMPOOL_ARRAY_H
#define _MEMPOOL_ARRAY_H
/*
typedef struct
{
    unsigned char used:1;
}mem_block_flag_t;

//定义了具体的内存块地址和该块内存是否被使用
typedef struct
{
    mem_block_flag_t *flag;
    void *addr;
}mem_block_t;
*/

typedef struct node
{
    void *addr;
    unsigned int mem_block_size;
    struct node *next;
}mem_block_t;

typedef struct
{
    mem_block_t *head;
    unsigned int mem_block_size;
    unsigned int mem_block_num;
}mem_block_list_t;

//定义了某种内存节点下有多少个内存块
typedef struct
{
    unsigned int mem_block_list_size;
    mem_block_list_t mem_block_list;
}mem_pool_node_t;

//定义了有多少种内存节点
typedef struct
{
    unsigned int mem_pool_node_size;
    mem_pool_node_t* mem_pool_node;
}mem_pool_t;

mem_pool_t *mem_pool_init(unsigned int types, ...);
void *malloc_from_mp(mem_pool_t *mp, unsigned int mem_block_size);
void free_to_mp(mem_pool_t *mp, void *addr);

#endif

