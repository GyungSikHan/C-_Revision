#include<iostream>
using namespace std;

bool IsExist(char (*arr)[6], char& c)
{
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            if(arr[i][j] == c)
                return true;
        }
        
    }
    return false;
}

int main()
{
    char arr[2][6]
    {
        'A','7','9','T','K','Q',
        'M','I','N','C','O','D'
    };

    char a[2];
    cin>>a[0]>>a[1];

    for (size_t i = 0; i < 2; i++)
    {
        cout<<a[i]<<" : "<<(IsExist(arr, a[i]) ? "존재":"없음")<<endl; 
    }
    
}