/*************************************************************************
	> File Name: test_softarray.c
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Sun 02 Sep 2018 02:46:20 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    int i;
    int tlen; 
    char t[];
}test_t;

typedef struct
{
    int i;
    int ii;
}test_tt;

int main(int argc, char *argv[])
{
    test_t *pt;
    test_tt *t;
    long int *pi;
   
    /*sizeof test*/
    printf("before sizeof int is %d\r\n", sizeof(*pi));//before sizeof int is 8
    printf("before sizeof test_tt is %d\r\n", sizeof(*t));//before sizeof test_tt is 8
    printf("before sizeof test_t is %d\r\n", sizeof(*pt));//before sizeof test_t is 8
   
    /*soft array test*/ 
    pt = malloc(sizeof(*pt) + sizeof("hello"));
    pt->tlen = sizeof("hello");
    strcpy(pt->t, "hello");
    printf("after sizeof test_t is %d\r\n", sizeof(*pt));//after sizeof test_t is 8
    printf("after pt->t:%s\r\n", pt->t);//after pt->t:hello
   
    free(pt);//t所占用的内存也将被释放，因为都是一malloc次分配出来的

    /*if t[1] is in test_t*/
    //printf("after pt->t size is %d\r\n", sizeof(pt->t)); 
    return 0;
}
