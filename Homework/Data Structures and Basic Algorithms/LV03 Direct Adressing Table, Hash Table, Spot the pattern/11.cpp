#include<iostream>
using namespace std;

int main()
{
    char arr[2][3]
    {
        'G','K','G'
    };
    for (size_t i = 0; i < 3; i++)
    {
        cin>>arr[1][i];
    }

    int ret[100]{};
    for (size_t i = 0; i < 6; i++)
    {
        ret[arr[i/3][i%3]]++;
    }

    bool bFlag{};
    for(int i = 'A'; i <= 'Z'; i++)
    {
        if(ret[i] >= 3)
        {
            bFlag = true;
            break;
        }
    }
    if(bFlag)
        cout<<"있음";
    else
        cout<<"없음";
    return 0;
}