#include <iostream>
using namespace std;

void IsExist(int *arr, int (*univer)[2], bool (*ret)[2])
{
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (arr[i] == univer[j/2][j%2])
            {   
                ret[j/2][j%2] = true;
            }
        }
    }
}

int main()
{
    int arr[6]{3, 7, 4, 1, 2, 6};
    int univer[2][2]{};
    bool ret[2][2]{};

    for (size_t i = 0; i < 4; i++)
    {
        cin >> univer[i / 2][i % 2];
    }

    IsExist(arr, univer, ret);


    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            if(ret[i][j])
                cout<<"OK"<<" ";
            else
                cout<<"NO"<<" ";
        }
        cout<<endl;
    }
    
}