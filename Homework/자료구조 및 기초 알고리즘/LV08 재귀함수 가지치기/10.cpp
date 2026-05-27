#include<iostream>
using namespace std;

int arr[3][4]
{
    3,5,4,1,
    1,1,2,3,
    6,7,1,2
};

void Trans(int* data , const int* trans, const int len)
{
    for (size_t i = 0; i < len-1; i++)
    {
        if(*data == trans[i])
        {
            *data = trans[i+1];
            return;
        }
    }
    
}

void Solve(const int* trans, const int len)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            Trans(&arr[i][j], trans, len);
        }
    }   
}

void Print()
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    int trans[4]{};
    for (size_t i = 0; i < 4; i++)
        cin>>trans[i];
    Solve(trans, 4);
    Print();
}