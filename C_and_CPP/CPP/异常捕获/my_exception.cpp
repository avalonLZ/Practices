/*************************************************************************
	> File Name: my_exception.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 21 Jan 2019 06:50:37 PM PST
	> Instruction:自己构建一个异常
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

//构建自己的异常
struct my_exception : public exception
{
    const char *what()
    {
        return "my_exception error";
    }
};

void my_exception_test(void)
{
    //通过throw关键字抛出自己构建的异常
    throw my_exception();
}

int main()
{
    try
    {
        my_exception_test();
    }
    catch(my_exception &e)//用catch捕获自己构建的异常
    {
        cout << e.what() << endl;
    }


    try
    {
        my_exception_test();
    }
    //expection也可以捕获到子类的异常
    //只不过what调用的就是exception中的方法了
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
