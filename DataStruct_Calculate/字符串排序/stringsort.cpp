/*************************************************************************
	> File Name: stringsort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月11日 星期二 01时30分18秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


class Createstring
{
    private:
        char *strone;
        unsigned char size;
    public:
        Createstring(string one);
        void Sort();
        void Display();
};

Createstring::Createstring(string one)
{
    size = one.size();
    strone = (char *)malloc (sizeof(char) * size + 1);
    strcpy(strone, one.c_str());
}

/*26个字母按ASCII排序，其他保持不变*/
void Createstring::Sort()
{
    unsigned char i,j;
    unsigned char k = 0;

    for(i = 0; i < size; ++i)
    {        
        if(strone[i] >= 65 && strone[i] <= 122)
        {
            for(j = i+1; j < size; ++j)
            {
                if(strone[j] >= 65 && strone[j] <= 122)
                {
                    if(strone[i] > strone[j])
                    {
                        strone[j] ^= strone[i];
                        strone[i] = strone[j] ^ strone[i];
                        strone[j] ^= strone[i];
                    }
                }
            }
        }
    }
}

void Createstring::Display()
{
    unsigned char i = 0;
    for(i = 0; i < size; ++i)
    cout << strone[i] << endl;    
}

int main()
{
    string i = "2jis,x lq8uKA";
    Createstring first(i);
    first.Sort();
    first.Display();
    return 0;
}
