/*************************************************************************
	> File Name: Test1_Template.h
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Mar 2017 02:49:01 AM PST
 ************************************************************************/

#ifndef _TEST1_TEMPLATE_H
#define _TEST1_TEMPLATE_H

namespace tep{

template<class T, int SIZE> class Stack{
private:
    T elems[SIZE];
    unsigned int ecount;

public:
    Stack();
    void push(const T &);
    void pop();
    bool empty() const{return ecount == 0;}
    bool full() const{return ecount == SIZE;}
    T top();
};
}
#endif
