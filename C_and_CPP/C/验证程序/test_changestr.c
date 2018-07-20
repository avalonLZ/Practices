/*************************************************************************
	> File Name: test_changestr.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: 2018年03月09日 星期五 04时17分24秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main(int argc, char *argv[])
{
    char *test = "1234";
    
    //*(test + 5) = 'a';
    *(test + 6) = 'b';
    //*(test + 7) = '\0';

    printf("%s\r\n", test);
    return 0;
}
