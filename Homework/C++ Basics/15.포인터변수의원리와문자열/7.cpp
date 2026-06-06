#include<iostream>
using namespace std;

int main()
{
    char arr[2][11]{};

    for (int i = 0; i < 2; i++)
    {
        cin>>arr[i];
    }

    int idx1{}, idx2{};
    while (arr[0][idx1] != '\0' || arr[1][idx2] != '\0')
    {
        if(arr[0][idx1] != '\0')
        {
            idx1++;
        }
        if(arr[1][idx2] != '\0')
        {
            idx2++;
        }
    }

    if(idx1 != idx2)
    {
        cout<<"거울문장아님";
        return 0;
    }

    bool bFlag{};
    int i{};
    while (i < idx1 && idx2 != 0)
    {
        if(arr[0][i] == arr[1][idx2-1])
        {
            i++;
            idx2--;
        }
        else
        {
            bFlag = true;
            break;
        }
    }

    if(bFlag)
        cout<<"거울문장아님";
    else
        cout<<"거울문장";
    
}