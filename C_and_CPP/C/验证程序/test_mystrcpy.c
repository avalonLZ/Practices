/*************************************************************************
	> File Name: test_mystrcpy.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Tue 08 Jan 2019 11:34:34 PM PST
	> Instruction:自写strcpy
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char *my_strcpy(char *a, char *b)
{
    char *tempa = a;
    do
        *(a++) = *(b++);
    while(*b != 0);//若b第一个为0也需要拷贝，所以不可将while放到前面

    return tempa;
}

int main(int argc, char *argv[])
{
    char *i = NULL;
    char a[10] = {0};

    i = my_strcpy(a, "lizhong");
    printf("%s\n", i);

    return 0;
}
