/*************************************************************************
	> File Name: sameclass.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Mar 2017 05:02:36 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

class Test
{
    private:
    int a;
    
    public:
    Test(){ a = 10; }
    void function(Test i)
    {
        cout << i.a + this->a << endl;
    }
};

int main()
{
    Test b;
    Test c;
    b.function(c);
    return 0;
}
