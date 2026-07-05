#include<iostream>
using namespace std;

int arr[4][3]
{
    3,5,1,
    3,1,2,
    3,4,6,
    5,4,6
};

int ret[7]{};

int main()
{
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 3; j++)
            ret[arr[i][j]]++;

    for (size_t i = 1; i < 7; i++)
    {
        for (size_t j = 0; j < ret[i]; j++)
        {
            cout<<'*'<<" ";
        }
        cout<<endl;
    }
    
    
}