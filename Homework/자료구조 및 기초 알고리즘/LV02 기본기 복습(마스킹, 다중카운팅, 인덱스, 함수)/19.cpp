#include<iostream>
using namespace std;

int main()
{
    int arr[4]{3,5,4,2};
    int mask[4]{};

    for (size_t i = 0; i < 4; i++)
    {
        cin>>mask[i];
    }

    int sum{};
    for (size_t i = 0; i < 4; i++)
    {
        if(mask[i] == 0)
            continue;

        sum+= arr[i];
    }
    
    cout<<sum;
}