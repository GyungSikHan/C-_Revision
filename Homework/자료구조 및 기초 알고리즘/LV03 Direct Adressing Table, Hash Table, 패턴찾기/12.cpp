#include<iostream>
using namespace std;

int main()
{
    int arr[10]{};
    bool bFlag{};
    for (size_t i = 0; i < 6; i++)
    {
        int a{};
        cin>>a;

        if(arr[a] != 0)
            bFlag = true;
        arr[a]++;
    }

    if(bFlag)
        cout<<"도플갱어 발견";
    else
        cout<<"미발견";

    return 0;
    
}