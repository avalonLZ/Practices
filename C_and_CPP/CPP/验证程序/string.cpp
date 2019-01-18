/*************************************************************************
	> File Name: string.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Thu 10 Jan 2019 09:52:48 PM PST
	> Instruction:string类常用实现
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>

using namespace std;


void string_test1(void)
{
    string s;
    s = "123";
    s += "sbc";
    //.c_str方法会返回char *类型的指针
    cout << s.c_str() << endl;
}

void string_test2(void)
{
    string s = "123abc";
    cout << s.length() << endl;
}

void string_test3(void)
{
    cout << "****************test3**************" << endl;
    string s = "cc1234";
    
    //推荐用substr方法截取字符串，而不使用string初始化的方式截取
    string s1 = s.substr(0, 2);//string(s, 0, 2);
    cout << "s1 = " << s1 << endl;
}

//测试读操作，超出string范围时
//结果说明，若超出string范围，执行也不会报错，不会抛出异常，所以需要注意string的范围
void string_test4(void)
{
    cout << "****************test4**************" << endl;
    string s = "1234";
    cout << s[10] << endl;
}

//测试find函数返回值
int string_test5(void)
{
    cout << "****************test5**************" << endl;
    string s = "abcd";

    //find没找到是返回-1，但是打印出该值则不是-1
    if(s.find('1') == -1)
        cout << "没有元素'1'" << endl;
    else
        cout << s.find("c") << endl;

}

int main(int argc, char *argv[])
{
    string_test1();
    string_test2();
    string_test3();
    string_test4();
    string_test5();
    return 0;
}
