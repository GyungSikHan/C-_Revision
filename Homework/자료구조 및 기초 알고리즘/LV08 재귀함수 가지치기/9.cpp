#include<iostream>
using namespace std;

void Sum(int (*arr)[4])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
            arr[i][3] += arr[i][j];
        for (size_t j = 0; j < 3; j++)
            arr[3][i] += arr[j][i];

        arr[3][3] += arr[i][i];
    }
}

void Print(const int (*arr)[4])
{
    for (size_t i = 0; i < 4; i++)
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
    int arr[4][4]{};
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            cin>>arr[i][j];  

    Sum(arr);
    Print(arr);
}