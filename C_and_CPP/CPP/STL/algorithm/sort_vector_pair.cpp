/*************************************************************************
	> File Name: sort_pair.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Mon 07 Jan 2019 06:53:47 PM PST
	> Instruction:sort算法配合vector嵌套pair容器
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
#include<utility>
#include<vector>
#include<cstdlib>
#include<algorithm>

#define PAIR_MAX 5

using namespace std;

//sort中使用的自定义比较函数，形参不可以是引用的形式
bool v_compare(pair<int, int> a, pair<int, int> b)
{
    //按第二个元素,升序排列
    return a.second < b.second;
}

void v_init(vector< pair<int, int> > &vec)
{
    unsigned int i = 0;
    
    for(i = 0; i < PAIR_MAX; ++i)
    {
        //将两个0~99的数随机数作为pair放入vec中
        vec.push_back(make_pair(rand()%100, rand()%100));
        vec.push_back(pair<int, int>(rand()%100, rand()%100));
    }
}

/*使用for_each算法替换自己遍历打印*/
void v_eprint(pair<int, int> a)
{
    cout << "(" << a.first << "," << a.second << ")" << endl;
}

/*
void v_print(const vector< pair<int, int> > &vec)
{
    unsigned int i = 0;
    
    //需要注意，const定义的容器，迭代器也需要是const的
    vector< pair<int, int> >::const_iterator iter;
    iter = vec.begin();
    cout << "vector print:" << endl;

    for(i = 0; i < vec.size(); ++i)
    {
        cout << "(" << iter->first << "," << iter->second << ")" << endl;
        ++iter;
    }
}
*/
int main(int argc, char *argv[])
{
    vector< pair<int, int> >v;
   
    cout << "排序前:" << endl;
    v_init(v);
    for_each(v.begin(), v.end(), v_eprint);
    //v_print(v);

    cout << "排序后:" << endl;
    sort(v.begin(), v.end(), v_compare);
    for_each(v.begin(), v.end(), v_eprint);
    //v_print(v);
    return 0;
}
