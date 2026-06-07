#include<iostream>
using namespace std;

void abc(int* arr, int idx)
{
    if(idx == 0)
    {
        cout<<arr[idx]<<" ";
        return;
    }

    cout<<arr[idx]<<" ";
    abc(arr,idx-1);
    cout<<arr[idx]<<" ";
}

int main()
{
    int idx{};
    int arr[8]{3,7,4,1,9,4,6,2};

    cin>>idx;
    abc(arr,idx);
}