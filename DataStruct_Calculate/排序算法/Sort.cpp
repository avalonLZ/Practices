/*************************************************************************
	> File Name: Sort.cpp
	> Author:lizhong 
	> Mail: 
	> Created Time: Tue 07 Mar 2017 06:11:01 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename T, unsigned char SIZE>
class Data{
    private:
        T data[SIZE];
        static unsigned char size;
    public:
        Data();
        Data(const T *a);
        void bubble_smalltobig();
        void select_bigtosmall();
        void insert_bigtosmall();
        void shell_smalltobig();
        void quick_smalltobig();
        unsigned char datasize() const;
};

template<typename T,unsigned char SIZE>
unsigned char Data<T, SIZE>::size = 0;

template <typename T, unsigned char SIZE>
Data<T, SIZE>::Data()
{
    unsigned char i;
    cout << "Please Input" << endl;
    for(i = 0; i < SIZE; i++)
    {
        cin >> data[i];
        this->size = i + 1;
    }
}

template<typename T, unsigned char SIZE>
Data<T, SIZE>::Data(const T *a)
{
    data = a;
}

template<typename T, unsigned char SIZE>
void Data<T, SIZE>::bubble_smalltobig()
{
    cout << "**********************Bubble:small to big*******************************" << endl;
    unsigned char i, j;

    /*遇到小的马上交换，交换后，用小的继续和下面的数比较，边比较（轮询）边换位*/
    for(i = 0; i < SIZE; i++)
    {
        for(j = i + 1; j < SIZE; j++)
        {
            if(data[i] > data[j])
            {
                /*i、j互换也可以实现交换*/
                data[j] ^= data[i];
                data[i] = data[j] ^ data[i];
                data[j] ^= data[i];
            }        
        }
    }
    
    for(i = 0; i < SIZE; i++)
    {
        cout << data[i] << " ";
    }

    if(i == SIZE)
    {
        cout << endl;
    }    
}

template<typename T, unsigned char SIZE>
void Data<T, SIZE>::select_bigtosmall()
{
    cout << "****************************Select:big to small**********************************" << endl;
    
    unsigned char i,j;
    unsigned char note = 0;//记录最大数的下角标

    /*先轮询一边，记录最大的数的下角标，之后在换位*/
    for(i = 0; i < SIZE ; i++)
    {
        note = i;
        for(j = i + 1; j < SIZE; j++)
        {
            if(data[note] < data[j])
                note = j;
        }
        if(note != i)
        {
            data[i] ^= data[note];
            data[note] = data[i] ^ data[note];
            data[i] ^= data[note];
        }
    }

     for(i = 0; i < SIZE; i++)
    {
        cout << data[i] << " ";
    }

    if(i == SIZE)
    {
        cout << endl;
    }
}

template<typename T, unsigned char SIZE>
void Data<T, SIZE>::insert_bigtosmall()
{
    cout << "*************************Insert:big to small*************************" << endl;
    int i,j,k = 0;
    T temp;
    
    /*取一个数去和可能插入的左方的数比较，如果该数大于左方的被比较数则移位，因为保证了之前就是大到小排列，所以排完一次就break*/
    for(i = 1; i < SIZE; i++)
    {
        temp = data[i];

        for(j = 0; j < i ; j++)
        {
            if(data[i] > data[j])
            {
                for(k = i - 1; k >= j; k--)
                {
                    data[k+1] = data[k];
                }
                data[j] = temp;
                break;
            }
        }
    }

    for(i = 0; i < SIZE; i++)
    {
        cout << data[i] << " ";
    }

    if(i == SIZE)
    {
        cout << endl;
    }
}

template<typename T, unsigned char SIZE>
void Data<T, SIZE>::shell_smalltobig()
{
    int i,j;
    int temp;

    //for(;;)

    for(i = 0; i < SIZE; i++)
    {
        cout << data[i] << " ";
    }

    if(i == SIZE)
    {
        cout << endl;
    }
}

template<typename T, unsigned char SIZE>
void Data<T, SIZE>::quick_smalltobig()
{
    
}
template<typename T, unsigned char SIZE>
unsigned char Data<T, SIZE>::datasize() const
{
    cout << "*******************************size********************************" << endl;
    return this->size;
}

int main()
{
    unsigned char i;
    Data<int ,10> one;
   // one.bubble_smalltobig();
   // one.select_bigtosmall();
    //one.insert_bigtosmall();
    one.quick_smalltobig();
    i = one.datasize();
    cout << int(i) << endl;
    return 0;
}
