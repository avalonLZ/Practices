/*************************************************************************
	> File Name: word_search1.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Fri 11 Jan 2019 04:53:32 AM PST
	> Instruction:查找一篇文章中某单词出现的次数(用拉链法解决are,ear这种问题)
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
#include<hash_map>

using namespace std;
using namespace __gnu_cxx;

//hash_map不支持string，所以要转成c_str才可以用
namespace __gnu_cxx {
        template<>
                struct hash<std::string>
                {
                            hash<char*> h;
                                    size_t operator()(const std::string &s) const
                                    {
                                                    return h(s.c_str());
                                                            
                                    };
                                        
                };
}

void world_count(hash_multimap<string, unsigned int> &hamap, string &s)
{
    hash_multimap<string, unsigned int>::iterator iter;
    
    iter = hamap.find(s);

    if(iter == hamap.end())
    {
        hamap.insert(pair<string, unsigned int>(s, 1));
        cout << s << " count = 1" << endl;
    }
    else
    {
        iter->second++;
        cout << s << " count = " << iter->second << endl;
    }
}

int main(int argc, char *argv[])
{
    hash_multimap<string, unsigned int> m;

    string ss[] = {"liz", "lizhong", "li", "l", "lizhong", "liz", "lizhong"};
    unsigned int i = 0;
    for(i = 0; i < sizeof(ss)/sizeof(string); ++i)
    {
        world_count(m, ss[i]);
    }

    return 0;
}


