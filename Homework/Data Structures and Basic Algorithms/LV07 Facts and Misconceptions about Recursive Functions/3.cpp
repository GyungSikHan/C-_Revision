#include<iostream>
using namespace std;

void Print(int* arr, int idx)
{
    cout<<arr[idx]<<" ";
}

void Backstep(int* arr, int size)
{
    if(size == 5)
    {
        Print(arr,size);
        return;
    }
    
    Print(arr,size);
    Backstep(arr, size+1);
    Print(arr,size);
}

int main()
{
    int arr[6]{};
    for (size_t i = 0; i < 6; i++)
        cin>>arr[i];
    Backstep(arr,0);    
}