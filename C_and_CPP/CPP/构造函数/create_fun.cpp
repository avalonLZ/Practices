/*************************************************************************
	> File Name: create_fun.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Wed 02 Jan 2019 05:04:18 PM PST
	> Instruction:构造函数重载实验
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class student
{
    private:
    int i;

    public:
    
    //实例化时，若不传参数，也是调用此函数
    //只可允许一次重载
    /*student(int n = 1)
    {
        cout << "create_class n=1" << endl;
        i = n;
    }*/
    
    student(int n = 1, int b = 11)
    {
        cout << "create_class n=1 b=11" << endl;
        i = b;
    }

    student(student &i)
    {
        cout << "copy_create_class" << endl;
    }

    ~student()
    {
        cout << "delete_class" << endl;
    }
    void get_i_value(void);
};

void student::get_i_value(void)
{
    cout << "i = " << i << endl;
}

int main(int argc, char *argv[])
{
    cout << "***********heap:***********" << endl;
    student *t = new student();
    t->get_i_value();
    delete t;

    cout << "***********stack:***********" << endl;
    student z(10,2);
    z.get_i_value();

    return 0;
}
