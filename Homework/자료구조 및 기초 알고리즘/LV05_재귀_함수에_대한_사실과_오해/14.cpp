#include<iostream>
using namespace std;


int main()
{
    int arr[7]{};   
    int size = 7;

    for (size_t i = 0; i < size; i++)
        cin>>arr[i];
    
    for (size_t i = 3; i < 7; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
    
}