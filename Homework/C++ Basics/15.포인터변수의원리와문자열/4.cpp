#include<iostream>
using namespace std;

int main()
{
    char arr[2][7]{};
    for (int i = 0; i < 2; i++)
    {
        cin>>arr[i];
    }

    int cnt[2]{};

    for(int i = 0; i<2; i++)
    {
        int count{};
        for(int j = 0; j< 7; j++)
        {
            if(arr[i][j] == '\0')
            {
                cnt[i] = count;
                break;
            }    
            count++;
        }
    }

    if(cnt[0] != cnt[1])
    {
        cout<<"lenght"<<endl;
        cout<<"다름"<<endl;
        return 0;
    }

    for(int i = 0; i<2; i++)
    {
        for(int j = i+1; j< 7; j++)
        {
            if(arr[i][j] == '\0')
            {
                break;
            }

            if(arr[i][j-1] < arr[i][j])
            {
                char temp = arr[i][j-1];
                arr[i][j-1] = arr[i][j];
                arr[i][j] = temp;
            }
        }
    }

    bool bFlag{};
    for(int i = 0 ; i <cnt[0]; i++)
    {
        cout<<arr[0][i]<<" "<<arr[1][i]<<endl;
        if(arr[0][i] != arr[1][i])
        {
            bFlag = true;
            break;
        }
    }
    if(bFlag)
    {
        cout<<"다름"<<endl;
    }
    else
    {
        cout<<"같음"<<endl;
    }
    
}