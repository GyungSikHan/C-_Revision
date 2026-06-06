#include<iostream>
using namespace std;

void check(int (*arr)[4])
{
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            cin>>arr[i][j];
}

bool solve(int (*arr)[4], int (*arr2)[4], int i, int j)
{
    if(j == 4)
        return false;
    if(i == 4)
    {
        i = 0;
        j++;
    }

    if(arr[i][j] == 1 && arr2[i][j] == 1)
        return true;
    return solve(arr, arr2, i+1, j);
}

int main()
{
    int a[4][4]{};
    int b[4][4]{};

    check(a);
    check(b);

    if(solve(a,b,0,0))
        cout<<"걸리다";
    else
        cout<<"걸리지않는다";    
}

