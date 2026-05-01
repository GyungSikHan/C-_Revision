#include<iostream>
using namespace std;

bool IsExist(const int arr[3][3], const int& data)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(arr[i][j] == data)
                return true;
        }
    }

    return false;
}

int main()
{
    int arr[3][3] = {
        {3,5,9},
        {4,2,1},
        {5,1,5}
    };

    int data{};
    for (size_t i = 0; i < 3; i++)
    {
        cin>>data;
        cout<<data<<":"<<(IsExist(arr, data) ? "존재" : "미발견") << endl;
    }
    
}