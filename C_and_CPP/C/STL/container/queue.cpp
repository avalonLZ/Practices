/*************************************************************************
	> File Name: queue.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Tue 30 Oct 2018 12:51:00 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
#include<queue>

using namespace std;

int main(int argc, char *argv[])
{
    queue<int> q1;
    int i = 0;

    for(i = 0; i < 11; ++i)
    {
        q1.push(i);
    }

    cout << "q1.front is:" << q1.front() << endl;
    cout << "q1.back is:" << q1.back() << endl;

    return 0;
}
