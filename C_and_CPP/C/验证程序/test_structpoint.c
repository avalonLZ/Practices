/*************************************************************************
	> File Name: test_point.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年03月21日 星期三 05时07分19秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct 
{
    char name;
    int age;
}child_t;

typedef struct 
{
    child_t c;
}father_t;

//int main(int argc, char *argv[])
//{
//    int *p;
//    int i = 10;
//    p = malloc(sizeof(int));
//    *p = i;
//    printf("%d\r\n", *p);
//    return 0;
//}

int main(int argc, char *argv[])
{
    father_t *f;

    f = malloc(sizeof(father_t));
    f->c.name = 'l';
    f->c.age = 24;
    printf("name = %c\r\nage = %d\r\n", f->c.name, f->c.age);
    return 0;
}
