/*************************************************************************
	> File Name: functemplate.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Mar 2017 06:36:56 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
void Function(const T &a)
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
