/*************************************************************************
	> File Name: shared.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sat 26 Jan 2019 07:29:55 PM PST
	> Instruction:shared_ptr试验
    注意：
    1、unique_ptr不可以转换为shared_ptr
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
#include<memory>

using namespace std;

int main(int argc, char *argv[])
{
    shared_ptr<string> pu1 = unique_ptr<string>(new string("2134"));
    shared_ptr<string> ps;

    ps = pu1;
    cout << *pu1 << endl;
    cout << *ps << endl;
    return 0;
}

