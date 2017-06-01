/*************************************************************************
	> File Name: Test1_Template.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Mar 2017 02:31:42 AM PST
 ************************************************************************/

#include<iostream>
#include"Test1_Template.h"
using namespace std;
using namespace tep;

template<class T, int SIZE>
Stack<T, SIZE>::Stack()
{
    ecount = 0;
}

template<class T, int SIZE>
void Stack<T, SIZE>::push(const T &element)
{
    elems[ecount] = element;
    ecount++;
}

template<class T, int SIZE>
void Stack<T, SIZE>::pop()
{
    ecount--;
}

template<class T, int SIZE>
T Stack<T, SIZE>::top()
{
    T i;
    i = elems[ecount - 1];
    ecount--;
    return i;
}


int main()
{
    char i = 'A';
    Stack<char, 10> onestack;
    onestack.push('B');
    cout << onestack.top() <<endl;
    return 0;
}
