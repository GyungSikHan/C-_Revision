#include<iostream>
using namespace std;
//o
const int len = 301;



int main()
{
    int n{};
    int nums[len]{};
    int ret[3]{};
    cin>>n;
    for (size_t i = 0; i < n; i++)
        cin>>nums[i];
    
    for (size_t i = 0; i < n; i++)
        ret[nums[i]]++;
    
    
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < ret[i]; j++)
        {
            cout<<i<<" ";
        }
    }
    
}