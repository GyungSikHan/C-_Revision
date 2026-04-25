#include<iostream>
using namespace std;

int main()
{
    char arr[5][11]{};
    int maxLength = -1;
    int maxIdx{};
    for (int i = 0; i < 5; i++)
    {
        cin>>arr[i];
        int temp{};
        for(int j = 0; j<11; j++)
        {
            if(arr[i][j] == '\0')
                break;
            temp++;
        }

        if(maxLength < temp)
        {
            maxLength = temp;
            maxIdx = i;
        }
    }

    cout<<arr[maxIdx];


    
}