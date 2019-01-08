/*************************************************************************
	> File Name: heapsort.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 07 Jan 2019 05:32:46 PM PST
	> Instruction:用STL中的priority_queue实现堆排序
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
#include<queue>
using namespace std;

void small_to_big(int *a, unsigned int size)
{
    //priority_queue升序排序,push后总是构建小顶堆
    priority_queue< int, vector<int>, greater<int> > q;
    int i = 0;

    for(i = 0; i < size; ++i)
    {
        q.push(a[i]);
    }

    cout << __FUNCTION__ << " priority_queue size is " << q.size() << endl;

    for(i = 0; i < size; ++i)
    {
        a[i] = q.top();
        cout << "array[" << i << "]" << " value is " << a[i] << endl;
        q.pop();
    }

}
void big_to_small(int *a, unsigned int size)
{
    //priority_queue默认降序排序,push后总是构建大顶堆
    priority_queue<int> q;
    int i = 0;

    for(i = 0; i < size; ++i)
    {
        q.push(a[i]);
    }

    cout << __FUNCTION__ << " priority_queue size is " << q.size() << endl;

    for(i = 0; i < size; ++i)
    {
        a[i] = q.top();
        cout << "array[" << i << "]" << " value is " << a[i] << endl;
        q.pop();
    }

}

int main(int argc, char *argv[])
{
    int array[] = {32,55,21,75,82,53,13,0,13,123};

    cout << "big->small:" << endl;
    big_to_small(array, (unsigned int)(sizeof(array)/sizeof(int)));

    cout << "***************************************" << endl;

    cout << "small->big:" << endl;
    small_to_big(array, (unsigned int)(sizeof(array)/sizeof(int)));

    return 0;
}
