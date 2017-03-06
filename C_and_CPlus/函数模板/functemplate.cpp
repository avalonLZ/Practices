/*************************************************************************
	> File Name: functemplate.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Mar 2017 06:36:56 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
void Function(const T &a)//函数模板一般都需要传递至少一个模板变量，否则无法完成函数功能
{
    T i;
    i = a;
    cout << i << endl;
}

int main()
{
    Function(1);//此处不能传字符串哦
    return 0;
}
