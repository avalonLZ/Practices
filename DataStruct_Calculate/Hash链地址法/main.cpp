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
    temp = first.DataOutput("three hello");
    
    cout << temp << endl;
    return 0;
}

