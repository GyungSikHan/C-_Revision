#include<iostream>
using namespace std;

int main()
{
    bool masking[6]{1,0,1,0,1,0};
    int arr[6]{};
    
    for (size_t i = 0; i < 6; i++)
    {
        cin>>arr[i];
    }
    

    int min = 987654321;
    int minIdx{};
    for (size_t i = 0; i < 6; i++)
    {
        if(!masking[i])
            continue;

        if(arr[i] < min)
        {
            min = arr[i];
            minIdx = i;
        }
    }

    cout<<"arr["<<minIdx<<"]="<<min;    

}
