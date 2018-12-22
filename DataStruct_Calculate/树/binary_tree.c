/*************************************************************************
	> File Name: binary_tree.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Fri 21 Dec 2018 07:24:17 PM PST
	> Instruction:二叉树的创建、销毁、根左右（先序）、左根右（中序）、左右根（后序）遍历--递归
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 9

//生成元素
int *Production_Element(int size)
{
    int *i;
    int index = 0;
    i = (int *)malloc(size * sizeof(int));

    for(index  = 0; index < size; ++index)
    {
        i[index] = index;
    }
    return i;
}

//二叉树结构
//树结构和节点结构相同
typedef struct node
{
    void *Data;
    struct node *lnode;
    struct node *rnode;
}*BinTree, BinNode;

void Create_Binary_Tree(int *i, int size, BinTree *T)
{
    if(size--)
    {
        //实例一个节点
        *T = malloc(sizeof(BinNode));
        memset(*T, 0, sizeof(BinNode));

        (*T)->Data = malloc(sizeof(int));
        *((int *)((*T)->Data)) = i[size];

        //填充左子树
        if(size % 2)
            Create_Binary_Tree(i, size, &(*T)->lnode);
        //填充右子树
        else
            Create_Binary_Tree(i, size, &(*T)->rnode);
    }
}

void Destory_Binary_Tree(BinTree *T)
{
    if(*T != NULL)
    {
        //销毁左子树
        Destory_Binary_Tree(&(*T)->lnode);
        //销毁右子树
        Destory_Binary_Tree(&(*T)->rnode);

        //销毁一个节点
        free(*T);
        *T = NULL;
    }
}

void Pre_Order_Traverse(BinTree T)
{
    if(T != NULL)
    {
        printf("this node value is %d\n", *(int *)T->Data);
        Pre_Order_Traverse(T->lnode);
        Pre_Order_Traverse(T->rnode);
    }
}

void In_Order_Traverse(BinTree T)
{
    if(T != NULL)
    {
        In_Order_Traverse(T->lnode);
        printf("this node value is %d\n", *(int *)T->Data);
        In_Order_Traverse(T->rnode);
    }
}

void Post_Order_Traverse(BinTree T)
{
    if(T != NULL)
    {
        Post_Order_Traverse(T->lnode);
        Post_Order_Traverse(T->rnode);
        printf("this node value is %d\n", *(int *)T->Data);
    }
}

int main(int argc, char *argv[])
{
    int *i = NULL;
    BinTree T = NULL;
    i = Production_Element(MAX_SIZE);

    //填充数据至二叉树
    Create_Binary_Tree(i, MAX_SIZE, &T);
    free(i);

    //前序遍历
    printf("**********root->left->right***********\n");
    Pre_Order_Traverse(T);
    printf("\n");

    //中序遍历
    printf("**********left->root->right***********\n");
    In_Order_Traverse(T);
    printf("\n");

    //后序遍历
    printf("**********left->right->root***********\n");
    Post_Order_Traverse(T);
    printf("\n");

    return 0;
}
