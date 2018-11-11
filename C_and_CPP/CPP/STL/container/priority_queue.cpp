/*************************************************************************
	> File Name: priority_queue.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Tue 30 Oct 2018 12:37:12 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
#include<queue>

using namespace std;

int main(int argc, char *argv[])
{
    priority_queue<int> pq1;
    int i = 0;
    
    for(i = 0; i < 11; ++i)
    {
        pq1.push(i);
    }

    cout << "top element is:" << pq1.top() << endl;
    return 0;
}
