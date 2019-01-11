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

int main(int argc, char *argv[])
{
    string_test1();

    return 0;
}
