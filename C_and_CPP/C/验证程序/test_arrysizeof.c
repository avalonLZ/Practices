/*************************************************************************
	> File Name: test_arrysizeof.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年01月26日 星期五 20时04分38秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdarg.h>

//array总是会退化为指针，无论怎样定义形参
void array_sizeof(int array[])
{
    printf("sizeof array = %d\n", sizeof(array));
}

int main(void)
{
    int a[2][3] = {0};

    printf("%d\r\n", sizeof(a));
   
    int b[10] = {0};
    array_sizeof(b);

    return 0;
}
