/*************************************************************************
	> File Name: functemplate.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Mar 2017 06:36:56 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
/*函数模板一般都需要传递至少一个模板变量，否则无法完成函数功能*/
void Function(const T &a)
{
    T i;
    i = a;
    cout << i << endl;
}

int main()
{
    string i = "123";
    /*此处想传字符串必须先定义一个string变量，直接放字符串编译器会认为是数组，导致后面的 i = a 编译报错*/
    Function(i);
   
    return 0;
}
