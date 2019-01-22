/*************************************************************************
	> File Name: string_error.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 21 Jan 2019 06:11:57 PM PST
	> Instruction:捕获string产生的异常
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
#include<exception>

using namespace std;

void string_error(void)
{
    string s = "1234";

    try
    {
        cout << s.at(5) << endl;
    }
    catch(exception &e)
    {
        cout << "function:" << __FUNCTION__ << " line:" << __LINE__\
            << " cause:" << e.what() << endl;
    }
}

int main(int argc, char *argv[])
{
    string_error();

    return 0;
}
