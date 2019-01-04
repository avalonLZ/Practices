/*************************************************************************
	> File Name: doublelist.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Thu 03 Jan 2019 05:29:28 PM PST
	> Instruction:双链表实现
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    void *data;
    unsigned int datasize;
    struct node *prinode;
    struct node *aftnode;
}*Node_t, Node;

typedef struct list
{
    Node_t head;
    Node_t end;
    unsigned int size;
}*List_t, List;

List_t ListInit(void)
{
    List_t list;
    list = malloc(sizeof(List));
    list->head = list->end = NULL;
    list->size = 0;
    return list;
}

void ListAddNode(List_t list, void *data, unsigned int datasize)
{
    Node_t tempnode;
    tempnode = malloc(sizeof(Node));
    tempnode->aftnode = tempnode->prinode = NULL;
    tempnode->data = malloc(datasize);
    memcpy(tempnode->data, data, datasize);
    tempnode->datasize = datasize;

    if(list->head == NULL)
    {
        list->head = list->end = tempnode;
    }
    else
    {
        list->end->aftnode = tempnode;
        tempnode->prinode = list->end;
        list->end = tempnode;
    }
    list->size++;
}
/*待调试
unsigned int ListSearchNode(List_t list, void *data, unsigned int datasize)
{
    unsigned int i = 0,j = 0;
    Node_t tempnode = list->head;
    
    for(i = 0; i < list->size; ++i)
    {
        if(tempnode->datasize == datasize)
        {
            while(1)
            {
                if(*(data + j) == *(tempnode->data + j) && j < datasize)
                {
                    ++j;
                    continue;
                }   
                else if(*(data + j) == *(tempnode->data + j) && j == datasize)
                    return i + 1; 
                else
                {
                    j = 0;
                    break;
                }
            }
        }
        tempnode = tempnode->aftnode;
    }
    return 0;
}
*/
void ListDeleteNode(List_t list, unsigned int j)
{
    unsigned int i = 0, index = j;
    Node_t tnode = NULL, tempnode = list->head;
    
    if(index != 0)
    {
        while(i != index - 1)
        {
           tempnode = tempnode->aftnode;
           ++i;
        }
        tnode = tempnode->prinode;
        
        if(tnode != NULL)
            tnode->aftnode = tempnode->aftnode;
        else//说明是头
            list->head = tempnode->aftnode;
        
        tnode = tempnode->aftnode;
        
        if(tnode != NULL)
            tnode->prinode = tempnode->prinode;
        else//说明是尾
            list->end = tempnode->prinode;

        free(tempnode->data);
        tempnode->data = NULL;
        free(tempnode);
        tempnode = NULL;
        list->size--;
    }   
}

void ListDeleteList(List_t list)
{
    Node_t tempnode = NULL;

    while(list->size)
    {
        tempnode = list->end->prinode;
        free(list->end->data);
        list->end->data = NULL;
        free(list->end);
        list->end = NULL;
        list->size--;
        list->end = tempnode;
    }
}

void ListPrint(List_t list)
{
    unsigned int i = 0;
    Node_t tempnode = NULL;
    tempnode = list->head;

    for(i = 0; i < list->size; ++i)
    {
        printf("data:%s\n", tempnode->data);
        tempnode = tempnode->aftnode;
    }
}

int main(int argc, char *argv[])
{
    List_t lt = ListInit();
    ListAddNode(lt, "li", strlen("li")+1);
    ListAddNode(lt, "zhong", strlen("zhong")+1);
    ListPrint(lt);
    ListDeleteNode(lt, 1);
    ListPrint(lt);
    return 0;
}


