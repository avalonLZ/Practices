/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Mar 2017 07:34:07 PM PDT
 ************************************************************************/

#include<iostream>
#include"virtulfun.h"
using namespace std;


int main()
{
    A *pa,*pb; 
    pa = new A;
    pb = new B;//父类的指针变量可以放派生类的指针
    A pA;
    B pB;

    pa->print();//执行A::print
    pb->print();//执行B::print
    pa->printt();//执行A::printt
    pb->printt();//执行A::printt，因为printt不是虚函数，所以派生类无法重写printt方法
    cout << "*****************************" << endl;
    pA.print();
    pA.printt();
    pB.print();
    pB.printt();

    return 0;
}
