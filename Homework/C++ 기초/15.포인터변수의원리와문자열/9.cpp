#include<iostream>
using namespace std;

int main()
{
    char arr[11]{};
    cin>>arr;
    
    bool bFlag{};
    for (int i = 0; i < 11; i++)
    {
        if(arr[i] == '\0')
            break;

        if((i % 2 == 1) && (arr[i] < 'a' || 'z' < arr[i]))
        {
            bFlag = true;
            break;
        }
        if((i % 2 == 0) && (arr[i] <'A' || 'Z'<arr[i]))
        {
            bFlag = true;
            break;
        }
    }

    if(bFlag)
        cout<<"일반문장";
    else
        cout<<"개구리문장";
    
}