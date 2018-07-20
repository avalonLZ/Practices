/*************************************************************************
	> File Name: test_structinit.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年03月09日 星期五 04时44分26秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct Test
{
    char name;
    int age;
};

static struct Test test = {.name  = 'a', .age  = 12};
//static struct Test test = {'a', 12};

int main(int argc, char *argv[])
{
    printf("name = %c\n\rage = %d", test.name, test.age);
    return 0;
}
