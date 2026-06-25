#include<iostream>
using namespace std;

int main()
{
    int arr[5][5] 
    {
        0,1,7,2,0,
        1,0,8,0,5,
        7,8,0,3,6,
        2,0,3,0,0,
        0,5,6,0,0
    };

    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            if(arr[i][j] != 0)
            {
                cout<<static_cast<char>('A' + i) <<" "<<static_cast<char>('A'+j)<<" "<<arr[i][j]<<endl;
                arr[i][j] = 0;
                arr[j][i] = 0;
            }
    
}