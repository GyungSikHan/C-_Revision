#include<iostream>
using namespace std;

int main()
{
    char arr[256]{};
    cin>>arr;
    char a{},b{};
    cin>>a;
    cin>>b;

    int idx{};
    while(arr[idx] != '\0')
    {
        if(arr[idx] == a)
            arr[idx] = b;

        idx++;
    }
    cout<<arr;
}