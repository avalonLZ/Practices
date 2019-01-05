/*************************************************************************
	> File Name: class_sizeof.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sat 05 Jan 2019 03:46:16 AM PST
	> Instruction:验证class中声明多个虚函数
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class fish
{
    public:
        virtual int f(void);
        virtual void fu(void);
        virtual char fun(void);
};

class cat
{

};

class li
{
    public:
        void p(void){};
};

int main(int argc, char *argv[])
{
    //需要存放虚函数表指针所以为8
    cout << sizeof(fish) << endl;

    //class都需要1
    cout << sizeof(cat) << endl;

    //函数不占空间,所以依然是1
    cout << sizeof(li) << endl;
    return 0;
}
