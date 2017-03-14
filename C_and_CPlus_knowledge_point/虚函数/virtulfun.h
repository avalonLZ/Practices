/*************************************************************************
	> File Name: virtulfun.h
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Mar 2017 07:34:16 PM PDT
 ************************************************************************/

#ifndef _VIRTULFUN_H
#define _VIRTULFUN_H

class A
{
    public:
        virtual void print();//定义一个虚函数，派生类可以将其重写
        void printt();
        virtual void printtt();
};

class B:public A
{
    public:
        void print();//重写父类A中的print函数
        void printt();
};

#endif
