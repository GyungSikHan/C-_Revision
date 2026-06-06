#include<iostream>
using namespace std;

int main()
{
    char arr[4][7]{};
    int length[4]{};

    for (int i = 0; i < 4; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < 4; i++)
    {
        int idx{};
        for (int j = 0; j < 7; j++)
        {
            if(arr[i][j] == '\0')
            {
                length[i] = idx;
                break;
            }
            idx++;
        }
    }


    for (int i = 0; i < 4; i++)
    {
        int minIdx = i;
        for (int j = i; j < 3; j++)
        {
            if(length[i] > length[i+1])
            {
                minIdx = i+1;
            }
        }
        if(minIdx != i)
        {
            int temp = length[minIdx];
            length[minIdx] = length[i];
            length[i] = temp;
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        cout<<length[i]<<" ";
    }
    
    
}