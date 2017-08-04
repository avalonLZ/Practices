/*************************************************************************
	> File Name: linked_list.c
	> Author: lizhong
	> Mail: 
	> Created Time: 2017年07月25日 星期二 17时30分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*节点结构*/
typedef struct node
{
    void *data;
    struct node *after_node;
    unsigned int count;
}*P_Node, Node;

/*链表结构*/
typedef struct
{
    P_Node head;
    P_Node end;
    unsigned int size;
}*P_Linked, Linked;

P_Linked LinkedList;

/*创建链表*/
void Linked_CreateLinked()
{
    LinkedList = malloc(sizeof(Linked));
    LinkedList->head = LinkedList->end = NULL;
}

/*插入节点*/
void Linked_InsertNode(void *data, unsigned int size)
{
    P_Node tempnode;

    tempnode = malloc(sizeof(Node));
    tempnode->data = malloc(size);
    memcpy(tempnode->data, data, size);
    tempnode->after_node = NULL;
    
    if(LinkedList->head == NULL)
    {
        tempnode->count = LinkedList->size = 0;
        LinkedList->head = LinkedList->end = tempnode; 
    }
    else
    {
        tempnode->count = ++LinkedList->size;
        LinkedList->end->after_node = tempnode;
        LinkedList->end = tempnode;
    }
}

/*删除节点*/
void Linked_DelNode(unsigned int c)
{
    unsigned int i = 0, j = 0;
    P_Node tempnode,delnode;

    tempnode = LinkedList->head;
    
    if(c == 0)
    {
        delnode = LinkedList->head;
        LinkedList->head = LinkedList->head->after_node;
        free(delnode->data);
        free(delnode);
    }
    else
    {
        for(i = 0; i < LinkedList->size - 1; ++i)
        {
            if(tempnode->after_node->count == c)
            {
                delnode = tempnode->after_node; 
                break;
            }
            else
            {
                tempnode = tempnode->after_node;
                continue;
            }    
        }
        tempnode->after_node = delnode->after_node;
        free(delnode->data);
        free(delnode);
    }
   LinkedList->size--;
}

/*打印所有节点*/
void Linked_DisplayAllNode()
{
    unsigned int i = 0;
    P_Node tempnode;
    tempnode = LinkedList->head;
    printf("All Elements is count:%d\n", LinkedList->size);

    for(i = 0; i <= LinkedList->size; ++i)
    {

        printf("this is %d : %s\n", i, (char *)tempnode->data);
        tempnode = tempnode->after_node;
    }
}

int main()
{
    unsigned char strone[] = "hello world";
    unsigned char strtwo[] = "hello lz";
    unsigned char strthree[] = "hello lizhong";
    Linked_CreateLinked();
    Linked_InsertNode((void *)strone,sizeof(strone));
    Linked_InsertNode((void *)strtwo,sizeof(strtwo));
    Linked_InsertNode((void *)strthree,sizeof(strthree));
    Linked_DisplayAllNode();
    Linked_DelNode(0);
    Linked_DisplayAllNode();
    return 0;
}
