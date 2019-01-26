/*************************************************************************
	> File Name: cut_string.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sat 26 Jan 2019 05:16:23 AM PST
	> Instruction:输入字符串，并按指定字符进行分割，最后输出
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
//#include<exception>
using namespace std;

int main(int argc, char *argv[])
{
    string s_all;
    cout << "请输入语句：" << endl;
    getline(cin, s_all);
   
    //未找到时返回npos,值为-1
    if(s_all.rfind(' ') == -1)
    {
        cout << "未输入分割字符" << endl;
    }
    else
    {

        cout << "您输入的语句是："<< "使用的分割字符是：'" << s_all.at(s_all.rfind(' ') + 1) << "'" << endl;
    }

    cout << s_all << endl;
    return 0;
}

