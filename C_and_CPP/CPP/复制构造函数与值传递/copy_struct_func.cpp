/*************************************************************************
	> File Name: copy_struct_func.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time: Wed 12 Dec 2018 06:00:58 AM PST
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class student
{
    public:
        student(){};

        student(const student &)
        {
            cout << "copy_struct_func" << endl;
        };

        void stprint(student a)
        {
            cout << "stprint" << endl; 
        };
};

int main(int argc, char *argv[])
{
    student st, dt;

    //从结果可知，会调用到student的复制构造函数student(const student &)
    st.stprint(dt);

    return 0;
}
