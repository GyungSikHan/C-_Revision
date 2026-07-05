#include<iostream>
using namespace std;

int main()
{
    int temp{};
    int arr[5]{};

    cin>>temp;

    for (size_t i = 0; i < 5; i++)
    {
        arr[i] = temp%10+1;
        temp /= 10;
    }
    
    
    for (size_t i = 0; i < 5; i++)
        cout<<arr[i];
}