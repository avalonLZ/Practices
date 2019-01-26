/*************************************************************************
	> File Name: test_pulsplus.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Thu 24 Jan 2019 12:56:04 AM PST
	> Instruction:验证*p++ = 'y'的执行优先级（先赋值再加加）
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void pointplusplus_equal(void)
{
    char c[10] = {'a','j','k','g','m','f'};
    char *p = c;

    printf("1 p address is:0x%x, value is:%c\n", p, *p);
    *p++ = 'y';//先*p = y;再p += 1;
    //*(p++) = 'y';//同上
    //(*p)++ = 'y';//报错，无法编译
    printf("2 p address is:0x%x, value is:%c\n", p, *p);

    printf("3 c address is:0x%x, value is:%c\n", c, *c);
}

void equal_pointplusplus(void)
{
    char c[10] = {'a','j','k','g','m','f'};
    char *p = c;
    char pp = 0;
    printf("0x%x, %c\n", p, pp);
    pp = *p++;//先pp = *p;再p += 1;
    printf("0x%x, %c\n", p, pp);
}

int main(int argc, char *argv[])
{
    pointplusplus_equal();
    equal_pointplusplus();
    return 0;
}
