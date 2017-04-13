/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月13日 星期四 01时15分20秒
 ************************************************************************/

#include"Simple_Hash_table.h"

int main()
{
    string temp;
    HashList first;
    first.DataInput("four hello");
    first.DataInput("second hello");
    first.DataInput("three hello");
    first.DataInput("th12345");
    first.DataInput("th33333");
    first.DataInput("th55555");
    temp = first.DataOutput("th12345");
    
    cout << temp << endl;
    return 0;
}

