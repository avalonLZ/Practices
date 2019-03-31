/*************************************************************************
	> File Name: test_arrayfunc.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sat 30 Mar 2019 10:37:49 PM PDT
	> Instruction:注册设备示例
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define DEV_NAME_MAX 10
#define DEV_SIZE_MAX 3

typedef int (*Func_t)(void *parm);

typedef struct dev
{
    char name[DEV_NAME_MAX];
    Func_t func;

}*Dev_t_p, Dev_t;

static Dev_t_p Dev_array[DEV_SIZE_MAX];

int Init_Dev(const char *name, Func_t func)
{
    static unsigned char dev_index = 0;
    
    if(dev_index >= DEV_SIZE_MAX)
        return -1;

    if(strlen(name) + 1 > DEV_NAME_MAX)
        return -2;
    
    Dev_array[dev_index] = (Dev_t_p)malloc(sizeof(Dev_t));
    
    strcpy(Dev_array[dev_index]->name, name);
    Dev_array[dev_index]->func = func;
    dev_index++;

    return 0;
}

Dev_t_p Get_Dev(const char *name)
{
    unsigned char index;
    
    while(Dev_array[index] != NULL)
    {
        if(strcmp(Dev_array[index]->name, name) == 0)
        {
            return Dev_array[index];
        }
        else
        {
            index++;
        }
    }

    return NULL;
}

int test1(void *t)
{
    printf("test1\n");
}

int main(int argc, char *argv[])
{
    Dev_t_p one = NULL;
    Init_Dev("test1", test1);
    one = Get_Dev("test1");
    one->func(NULL);
    return 0;
}
