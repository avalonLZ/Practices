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
    //内核所采用的结构体初始化方式
    struct Test mtest = {.name  = 'b', .age  = 24};
    
    printf("name = %c\n\rage = %d\n", test.name, test.age);
    printf("name = %c\n\rage = %d\n", mtest.name, mtest.age);
    return 0;
}
