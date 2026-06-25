#include<iostream>
using namespace std;

const int len = 4;

void Input(int (*arr)[len])
{
    for (size_t i = 0; i < len; i++)
        for (size_t j = 0; j < len; j++)
            cin>>arr[i][j];
}

char Solution(int (*arr)[len])
{
    int idx{};
    int Max = -987654321;
    for (size_t i = 0; i < len; i++)
    {
        int temp{};
        for (size_t j = 0; j < len; j++)
        {
            if(arr[i][j] == 1)
                temp++;
        }
        
        if(Max < temp)
        {
            idx = i;
            Max = temp;
        }
    }
    
    return 'A' + idx;
}

int main()
{
    int arr[len][len]{};
    Input(arr);
    cout<<Solution(arr);

}