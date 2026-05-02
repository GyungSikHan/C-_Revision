#include<iostream>
using namespace std;

void Masking(int (*masking)[3])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cin>>masking[i][j];
        }
    }
}

bool Check(int (*arr)[3], int (*masking)[3])
{
        for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(masking[i][j] == 0)
                continue;

            if(3<= arr[i][j] && arr[i][j] <= 5)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int arr[3][3]
    {
        3,1,9,
        7,2,1,
        1,0,8
    };

    int masking[3][3]{};
    Masking(masking);
    if(Check(arr, masking))
        cout<<"발견";
    else
        cout<<"미발견";

}