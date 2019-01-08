/*************************************************************************
	> File Name: stack.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 07 Jan 2019 05:15:31 PM PST
	> Instruction:栈容器实验
 ************************************************************************/
#include<iostream>
#include<string>
#include<stack>
#include<string.h>
using namespace std;

int main(int argc, char *argv[])
{
    stack<int> s;
    unsigned int i = 0;;
    unsigned int size = 0;

    for(i = 0; i < 10; ++i)
    {
        s.push(i);
    }

    size = s.size();
    cout << "stack size is " << size << endl;

    while(size--)
    {   
        cout << "index " << size << " value is " << s.top() << endl;
        s.pop();
    }
    return 0;
}
