/*************************************************************************
	> File Name: string.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Thu 10 Jan 2019 09:52:48 PM PST
	> Instruction:string类常用实现
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>

using namespace std;


void string_test1(void)
{
    string s;
    s = "123";
    s += "sbc";
    cout << s.c_str() << endl;
}

void string_test2(void)
{
    string s = "123abc";
    cout << s.length() << endl;
}

void string_test3(void)
{
    cout << "****************test3**************" << endl;
    string s = "cc1234";
    
    //推荐用substr方法截取字符串，而不使用string初始化的方式截取
    string s1 = s.substr(0, 2);//string(s, 0, 2);
    cout << "s1 = " << s1 << endl;
}

int main(int argc, char *argv[])
{
    string_test1();
    string_test2();
    string_test3();
    return 0;
}
