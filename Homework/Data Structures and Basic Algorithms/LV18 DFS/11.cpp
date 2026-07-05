#include<iostream>
using namespace std;

int arr[5]{};

bool Check(int a, int b)
{
    return a < b;
}

int main()
{
    for (size_t i = 0; i < 5; i++)
        cin>>arr[i];

    bool bFlag{};
    for (size_t i = 0; i < 4; i++)
    {
        if(!Check(arr[i], arr[i+1]))
        {
            bFlag = true;
            break;
        }
    }
    
    if(bFlag)
        cout<<"증가안됨";
    else
        cout<<"증가됨";
}