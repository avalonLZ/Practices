/*************************************************************************
	> File Name: friendfun.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Mar 2017 10:51:56 PM PDT
 ************************************************************************/

#include<iostream>
#include"friendfun.h"

using namespace std;

Friendfun::Friendfun()
{
    i = "Hello Friend Function";
}

void Friendfun::fprint()
{
    cout << i  << endl;
}

/*友元函数的实现*/
void change(Friendfun &f)
{
    f.i = "Hello Friend Function changed";
}

int main()
{

    Friendfun fun;
    fun.fprint();
    change(fun);//调用友元函数改变fun中的i私有成员变量
    fun.fprint();
    
    return 0;
}
