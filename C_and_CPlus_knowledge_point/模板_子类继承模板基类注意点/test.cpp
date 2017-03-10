/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 05 Mar 2017 04:39:50 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T> class Testone;

template <typename T> class Testone{
    public:
    void p(T i){cout << "testone!" << i << endl;}
};

/*模板子类继承模板基类需要加相同的模板参数*/
template<typename P> class Testtwo : public Testone<P>{
    public:
    void b();
};
