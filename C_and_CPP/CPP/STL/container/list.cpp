/*************************************************************************
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
    return 0;
}
