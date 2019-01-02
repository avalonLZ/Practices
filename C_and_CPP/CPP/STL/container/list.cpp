/************************************************************************
	> File Name: list.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Mon 29 Oct 2018 01:27:51 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
#include<list>

using namespace std;


int main(int argc, char *argv[])
{
    list<string> l1(10);
    list<string>::iterator index = l1.begin();

    *index = "abi";
    index++;
    *index = "zhong";
    index++;
    *index = "abc";
    
    for(index = l1.begin(); index != l1.end(); ++index)
    {
        cout << "value = " << *index << endl;
    }

    l1.sort();

    for(index = l1.begin(); index != l1.end(); ++index)
    {
        cout << "value = " << *index << endl;
    }

    //双向迭代器不支持大小比较,以下内容会报错
    //list<string>::iterator begin = l1.begin;
    //if(begin < index)
    //    cout << "begin < index" << endl;
    //else
    //    cout << "begin >= index" << endl;

    //return 0;
}
