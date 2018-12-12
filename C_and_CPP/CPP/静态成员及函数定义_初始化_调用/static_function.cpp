/*************************************************************************
	> File Name: static_function.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Tue 11 Dec 2018 07:36:28 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class student
{
    private:
        static int pri_func()//私有的静态成员函数，外部总是无法访问
        {
            cout << "pri_hello" << endl;
        };

    public:
        static int pub_func()//公有的静态成员函数，外部可以通过类::成员函数名()进行访问
        {
            cout << "pub_hello" << endl;    
        };
        static int pub_func2();

    protected:
        static int pro_func();
};

//外部成员函数，可以在类外进行定义
int student::pub_func2()
{
    cout << "pub_hello2" << endl;
}

int main(int argc, char *argv[])
{
    student::pub_func();
    student::pub_func2();
    return 0;
}
