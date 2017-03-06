/*************************************************************************
	> File Name: funsamcla.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 06 Mar 2017 05:59:40 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

class Funone
{
    private:
        int a;
    public:
        Funone(){ a = 11; }
};

int operator+(Funone i,int a )
{
     return 100 + a ;
}

int main()
{
    Funone q;
    cout << q + 10 << endl;
    return 0;
}
