/*************************************************************************
	> File Name: point_test.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年01月24日 星期三 02时02分36秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdarg.h>


typedef struct{
    int i;
}Test_t;

int main(void)
{
    char *i;
    static char ii = 'a';
    Test_t iii = {1};
    printf("%d\r\n", (unsigned char)iii.i);
    i = (char *)0x804a020;
    printf("%c\r\n", *i);
    return 0;
}
