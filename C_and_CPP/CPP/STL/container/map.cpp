/*************************************************************************
	> File Name: map.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Mon 29 Oct 2018 06:29:35 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
#include<map>

using namespace std;

int main(int argc, char *argv[])
{
    map<int, string> m1;
    
    m1.insert(map<int, string>::value_type(2, "zhong"));
    m1.insert(pair<int, string> (1, "li"));
    m1.insert(pair<int, string> (2, "def"));
    m1.insert(map<int, string>::value_type(2,"hjk"));
    m1[3] = "abc";

    cout << "first_element_key is:" << m1.begin()->first << "," << "first_element_value is:"  << m1.begin()->second << endl;

    map<int, string>::reverse_iterator rindex = m1.rbegin();
    cout << "end_element_key is:" << rindex->first << "," << "end_element_value is:" << rindex->second << endl;

    cout << "map_size is;" << m1.size() << endl;
    cout << "map_count is:" << m1.count(2) << endl;
    return 0;
}
