/*************************************************************************
	> File Name: stl_vector_point.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Tue 08 Jan 2019 06:55:25 PM PST
	> Instruction:
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

typedef struct
{
    void *data;
    int index;
}Node_t;

int main(int argc, char *argv[])
{
    int i = 111;
    vector<Node_t *> v;
    vector<Node_t *>::iterator iter;
    Node_t *node = NULL;
    node = new Node_t;
    node->data = new int;
    memcpy(node->data, &i, sizeof(int));
    node->index = 222;
    v.push_back(node);
    iter = v.begin();

    //存放指针的容器，其迭代器需要看成是指向指针的指针
    cout << *(int *)(*iter)->data << endl;
    cout << (*iter)->index << endl;

    return 0;
}
