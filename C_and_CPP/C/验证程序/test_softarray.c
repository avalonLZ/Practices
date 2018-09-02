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
    printf("before sizeof int is %d\r\n", sizeof(*pi));
    printf("before sizeof test_tt is %d\r\n", sizeof(*t));
    printf("before sizeof test_t is %d\r\n", sizeof(*pt));//1
   
    /*soft array test*/ 
    pt = malloc(sizeof(*pt) + sizeof("hello"));
    pt->tlen = sizeof("hello");
    strcpy(pt->t, "hello");
    printf("after sizeof test_t is %d\r\n", sizeof(*pt));//还是1
    printf("after pt->t:%s\r\n", pt->t);
    
    /*if t[1] is in test_t*/
    //printf("after pt->t size is %d\r\n", sizeof(pt->t)); 
    return 0;
}
