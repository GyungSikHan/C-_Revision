#include<iostream>
using namespace std;

void MakeZero(int arr[4])
{
    for (size_t i = 0; i < 4; i++)
    {
        arr[i] = 0;
    }
}

int main()
{
    int arr[7][4]{};
    int data = 1;
    for (size_t i = 0; i < 7; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            arr[i][j] = data++;
        }
    }

    int a{},b{},c{};
    cin>>a>>b>>c;
    
    MakeZero(arr[a]);
    MakeZero(arr[b]);
    MakeZero(arr[c]);

    for (size_t i = 0; i < 7; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}