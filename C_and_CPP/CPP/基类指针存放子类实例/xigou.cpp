/*************************************************************************
	> File Name: xigou.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sat 27 Apr 2024 09:27:57 PM PDT
	> Instruction:
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class base_a {
    public:
        ~base_a() {
            cout << __FUNCTION__ << endl;
        }
};

class a:public base_a {
    public:
        ~a() {
            cout << __FUNCTION__ << endl;
        }
};

class base_b {
    public:
        virtual ~base_b() {
            cout << __FUNCTION__ << endl;
        }
};

class b:public base_b {
    public:
        ~b() {
            cout << __FUNCTION__ << endl;
        }
};

int main(int argc, char *argv[]) {
    //下面这种用法较为常见（基类指针存放子类实例）
    //因为可以通过基类的实现，去限制子类能使用的接口
    //在基类中是虚函数的，才可以被使用（在虚函数表中能被找到）
    //在这种情况下就一定需要虚析构函数，否则子类析构函数将无法被调用到
    base_a *jj = new(a);
    delete jj; //只调用到了基类析构函数

    cout << "*********************************" << endl;

    base_b *ii = new(b);
    delete ii;//调用到了子类和基类析构函数

    return 0;
}
