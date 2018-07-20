/*************************************************************************
	> File Name: struct_assignment.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月21日 星期二 07时00分47秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char strs[4];
    int i;
    unsigned char ii;

}Test_t;


int main(void)
{
    Test_t t1 = {0};
    t1.i = 100;
    Test_t t2;

    t2 = t1;
    printf("%d\r\n", t2.i);
}
