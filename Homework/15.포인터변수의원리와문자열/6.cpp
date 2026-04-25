#include<iostream>
using namespace std;

int main()
{
    int arr[6]{};

    for (int i = 0; i < 6; i++)
    {
        cin>>arr[i];
    }

    bool bFlag{};
    for (int i = 0; i < 5; i++)
    {
        int temp = arr[i] - arr[i+1];

        if(temp < 0)
            temp *= -1;

        if(3 < temp)
        {
            bFlag = true;
            break;
        }
    }

    if(bFlag)
        cout<<"재배치필요";
    else
        cout<<"완벽한배치";
    
    
}