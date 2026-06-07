#include<iostream>
using namespace std;

void Masking(int mask[3][3])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cin>>mask[i][j];
        }
        
    }
    
}

int main()
{
    int arr[3][3]
    {
        3,5,9,
        4,2,1,
        1,1,5
    };
    int mask[3][3]{};
    Masking(mask);

    int sum{};
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (mask[i][j] == 1)
                sum += arr[i][j];
        }
    }

    cout<<sum;
    
}