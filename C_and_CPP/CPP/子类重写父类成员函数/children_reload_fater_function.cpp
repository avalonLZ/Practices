/*************************************************************************
	> File Name: children_reload_fater_function.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sun 23 Dec 2018 09:23:46 PM PST
	> Instruction:子类重写父类成员函数（注意，在非同一个类中没有重载的概念）
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class father
{
    public:
        void my_print()
        {
            cout << "father" << endl;
        }
};

class children : public father
{
    public:
        void my_print()
        {
            cout << "children" << endl;
        }
};

int main(int argc, char *argv[])
{
    children c;
    c.my_print();
    cout << "**************************" << endl;
    father *pc = new children;//父类的指针允许存放子类的实例，反之则不可
    pc->my_print();//非虚函数，所以调用的是父类中的方法
    return 0;
}
