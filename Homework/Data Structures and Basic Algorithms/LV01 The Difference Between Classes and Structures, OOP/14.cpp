#include<iostream>
using namespace std;

int main()
{
    int idx{},idx2{};
    cin>>idx>>idx2;

    int arr[6]{};
    arr[0] = idx;
    arr[1] = idx2;

    int idx3 = 2;
    for (int i = 1; i < 6 && idx3 < 6; i++)
    {
        arr[idx3++] = arr[i-1]*arr[i];
    }

    cout<<arr[5];
    
    
}