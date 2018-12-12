/*************************************************************************
	> File Name: static_member_fun.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Tue 11 Dec 2018 06:35:27 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class student
{
    private:
        //char pri_name1 = 'a';
        static char pri_name2;//私有的静态成员变量，外部总是无法访问

        //static char pri_name = 'a';
    public:
        static char pub_name2;//公有的静态成员变量，外部可以通过类::变量名或实例.变量名进行访问
        //static char pub_name;
    protected:
        //static char pro_name;

};

char student::pri_name2 = 'a';
char student::pub_name2 = 'b';

int main(int argc, char *argv[])
{
    cout << student::pub_name2 << endl;
    return 0;
}
