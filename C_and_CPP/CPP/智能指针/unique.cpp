/*************************************************************************
	> File Name: unique.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sat 26 Jan 2019 06:45:46 PM PST
	> Instruction:unique智能指针试验（unique_ptr只可用作移动，不支持copy等操作）
    注意：
    1、在此例中，*解引用后，表示的是一个string类
    2、编译时需要使用c++11特性，需要加入-std=c++11该编译选项
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
#include<memory>
using namespace std;

int main(int argc, char *argv[])
{
    unique_ptr<string> q1 = unique_ptr<string> (new string("abcdefg"));
    unique_ptr<string> q2;

    //unique_ptr保证指针所有权不被变化
    //需使用move方法才能移动其所有权
    //q2 = q1;//编译报错，auto_ptr会在程序运行中，多次释放指针时core dump
    
    q2 = move(q1);//q1将不可访问
    cout << "q2:" << (*q2)[3] << endl;
    //cout << "q1:" << *q1 << endl;//move后将报错，因为q1以及指向null
    //unique_ptr<string> q3(q1);//报错，不支持
    //cout << "q3:" << *q3 << endl;

    return 0;
}
