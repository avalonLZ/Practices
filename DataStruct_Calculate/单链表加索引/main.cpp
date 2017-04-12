/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月11日 星期二 22时47分38秒
 ************************************************************************/

#include"queue.cpp"


int main()
{
    unsigned long int i,ii,iii;
    char *temp;
    Queueclass<char> first;
    char c1[] = "first";
    char c2[] = "second";
    char c3[] = "three";
    i = first.Input(c1);
    ii = first.Input(c2);
    iii = first.Input(c3);

    temp = first.Output(3);

    cout << temp[1] << endl;
    return 0;
}
