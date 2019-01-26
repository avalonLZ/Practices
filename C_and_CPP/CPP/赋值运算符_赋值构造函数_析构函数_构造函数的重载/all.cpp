/*************************************************************************
	> File Name: equal_reload.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Wed 02 Jan 2019 05:46:48 PM PST
	> Instruction:验证默认的赋值运算符和复制构造函数，是否是深拷贝，并进行重载赋值运算符实验
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;

class teacher
{
    private:
        int i;

    public:
        char *c;

        teacher(int n = 1)
        {
            i = 0;
            c = new char(strlen("hello world!") + 1);
            memcpy(c, "hello world!", strlen("hello world!") + 1);
            cout << "teacher create func" << endl;
        }

    //采用默认复制构造函数
    //采用默认赋值运算符
    //采用默认的析构函数
};


class student
{
    private:
    int i;

    public:
    char *c;

    student()
    {
        i = 0;
        c = new char(strlen("hello world!") + 1);
        memcpy(c, "hello world!", strlen("hello world!") + 1);
        cout << "create_func" << endl;
    }

    //复制构造函数
    student(student &s)
    {
        i = s.i;
        c = new char(strlen(s.c) + 1); 
        memcpy(c, s.c, strlen(s.c) + 1);
        cout << "copy_func" << endl;
    }

    //赋值运算符重载标准写法
    student& operator=(const student &x)
    {
        cout << "equal_func" << endl;
        //必须先判断是否是同一地址
        //不是同一地址，则继续
        if(this != &x)
        {
            i = x.i;

            if(c != NULL)
                delete c; 
            
            //在cpp中new失败，不会返回NULL，而是抛出异常
            try
            {
                c = new char(strlen(x.c) + 1); 
            }
            catch(const bad_alloc &e)
            {
                c = NULL;
            }
            
            if(c != NULL)
                memcpy(c, x.c, strlen(x.c) + 1);
        }
        return *this;
    }

    ~student()
    {
        cout << "delete_func,c address is" << (void *)c << endl;

        if(c != NULL)
        {
            delete c;
            c = NULL;
        }
    }
};

void default_copy_equal(void)
{ 
    cout << "teacher *t = new teacher:" << endl;
    teacher *t = new teacher;
    cout << "t->c address:" << (void *)t->c << endl;

    cout << "teacher tt = *t:" << endl;
    teacher tt = *t;
    cout << "tt.c address:" << (void *)tt.c << endl;
    
    cout << "teacher ttt,ttt = *t:" << endl;
    teacher ttt;
    ttt = *t;
    cout << "ttt.c address:" << (void *)ttt.c << endl;

    cout << "delete t:" << endl;
    delete t;//可以发现，所有地址都一样，说明默认用的是浅拷贝
    cout << "**********************************************" << endl;
}

int main(int argc, char *argv[])
{

    default_copy_equal();

    cout << "student *t = new student:" << endl;
    student *t = new student;//只调用构造函数
    cout << "t->c address:" << (void *)t->c << endl;

    cout << "student tt = *t:" << endl;
    
    //注意此处只会调用拷贝构造函数
    //而不会调用构造函数
    //与将变量之间作为形参传递的情况相同
    student tt = *t;
    cout << "tt.c address:" << (void *)tt.c << endl;
    
    cout << "student ttt,ttt = *t:" << endl;
    student ttt;//调用构造函数
    ttt = *t;//调用重载后的赋值操作符
    cout << "ttt.c address:" << (void *)ttt.c << endl;

    cout << "delete t:" << endl;
    delete t;

    return 0;
}
