/*************************************************************************
	> File Name: xigou.cpp
	> Author:lizhong
	> Mail:423810942@qq.com
	> Created Time:Sat 27 Apr 2024 03:38:29 AM PDT
	> Instruction:
 ************************************************************************/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class my {
    private:
        int i;

    public:
        my(int lz) {
            i = lz;
            cout << "gouzao..." << i << endl;
        }

        my(const my &a) {
            //private的变量，在class中还是可以随便使用的
            i = a.i + 1;
            cout << "fuzhi gouzao..." << i << endl;
        }

        ~my(){
            cout << "xigou..."  << i << endl;
        }


};

int main(int argc, char *argv[]) {
    
    my a(123);//构造函数
    my b = a;//复制构造
    my c(a);//调用的依然是复制构造函数
    my d(*new int(999));//调用的是构造函数

    return 0;
}
