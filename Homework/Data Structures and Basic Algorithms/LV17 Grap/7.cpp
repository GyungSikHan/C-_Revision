#include<iostream>
using namespace std;
const int y = 3;
const int x = 4;
void InputArray(int* arr)
{
    for(int i = 0; i<x; i++)
        cin>>arr[i];
}

void Solution(int (*arr)[x] )
{
    for (size_t i = 1; i < y; i++)
    {
        for (size_t j = 1; j < x; j++)
        {
            int dy = i-1;
            int dx = j-1;

            if(dy < 0 || dx < 0)
                continue;

            arr[i][j] = arr[dy][j]+arr[i][dx];
        }
    }
}

void Print(int  (*arr)[x])
{
    for(int i = 0; i< y; i++)
    {
        for (size_t j = 0; j < x; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[y][x]
    {
        0,0,0,0,
        1,0,0,0,
        1,0,0,0
    };

    InputArray(arr[0]);
    Solution(arr);
    Print(arr);
}