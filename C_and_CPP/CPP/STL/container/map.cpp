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
    map<int, string>::iterator m1_iter;// = m1.begin();
    int m1_index = 0;

    m1.insert(map<int, string>::value_type(2, "zhong"));
    m1.insert(pair<int, string> (1, "li"));
    m1.insert(pair<int, string> (2, "def"));
    m1.insert(map<int, string>::value_type(2,"hjk"));
    m1[3] = "abc";

    //迭代
    //一定需要在填充元素后再获取首元素，否则地址不对
    for(m1_index = 0, m1_iter = m1.begin(); m1_index < m1.size(); ++m1_index, ++m1_iter)
    {
        cout << "index is " << m1_index << " " << "key is" << m1_iter->first << " " << "element is" << m1_iter->second << endl;
    }

    //打印第2个元素,暂时只能想到用for加index的方式来找第n个key和value
    m1_iter = m1.begin();
    for(m1_index = 0, m1_iter = m1.begin(); m1_index < m1.size(); ++m1_index, ++m1_iter)
    {
        if(m1_index == 1)//从0开始
        {
            cout << "second key is " << m1_iter->first << " " << "second value is " << m1_iter->second << endl;
        } 
    }
    
    //这样表示错误
    //cout << "second element is " << (m1_iter + 2)->second << endl;
    //这样表示错误
    //cout << "second element is " << m1_iter[2]->second << endl;

    cout << "first_element_key is:" << m1.begin()->first << "," << "first_element_value is:"  << m1.begin()->second << endl;

    map<int, string>::reverse_iterator rindex = m1.rbegin();
    cout << "end_element_key is:" << rindex->first << "," << "end_element_value is:" << rindex->second << endl;

    cout << "map_size is;" << m1.size() << endl;
    cout << "map_count is:" << m1.count(2) << endl;
    return 0;
}
