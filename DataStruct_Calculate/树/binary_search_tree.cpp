/*************************************************************************
	> File Name: binary_search_tree.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 07 Jan 2019 11:02:56 PM PST
	> Instruction:二叉查找树的构建及遍历(未完成)
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>

#define VECTOR_MAX 11

using namespace std;

typedef struct node
{
    void *data;
    struct node *lnode;
    struct node *rnode;
}*BinTree_t, BinNode_t;

void Vector_InitRand(vector<int> &v, unsigned int size)
{
    //添加0~99范围内的数size个
    while(size--)
        v.push_back(rand()%100);
}

void BinTree_Init(const vector<int> &v, BinTree_t &t)
{
    BinTree_t tree;
    vector<BinTree_t> node_stack;
    vector<BinTree_t>::iterator iter_stack;
    vector<int>::const_iterator iter;

    for(iter = v.begin(); iter < v.end(); ++iter)
    {
        tree = new BinNode_t;
        memset(tree, 0, sizeof(BinNode_t));
        tree->data = new int;
        *(tree->data) = *iter;
        
        iter_stack = node_stack.begin();
    
        if(node_stack.size() == 0)
        {
            t = tree;
        }
        else if()
        {

        }
        else
        {
            
        }
        
        node_stack.push(tree);
    }
}

int main(int argc, char *argv[])
{
    vector<int> vec;
    BinTree_t tr = NULL;

    Vector_InitRand(vec, VECTOR_MAX);


    return 0;
}

