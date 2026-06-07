#include<iostream>
using namespace std;

void Fill(int* arr, const int* len,const int* data)
{
    for (size_t i = 0; i < *len; i++)
        arr[i] = *data;
}

int main()
{
    int arr[3][2][3]{};
    int a{},b{};
    cin>>a>>b;

    int len = 3;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            if(j == 0)
                Fill(arr[i][j], &len, &a);
            else
                Fill(arr[i][j], &len, &b);
        }   
    }
    
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                cout<<arr[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }
}