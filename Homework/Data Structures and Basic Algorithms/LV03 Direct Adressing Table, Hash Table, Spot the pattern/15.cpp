#include <iostream>
using namespace std;

int FindIdx(const char* str, const char c, bool bReverse = false)
{
    if(bReverse)
    {
        for (size_t i = 9; i >= 0; i--)
        {
            if(str[i] == c)
                return i+1;            
        }
        
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            if(str[i] == c)
            return i+1;
        }
    }

    return -1;
}
int main()
{
    char str[10]="ATKPTCABC";

    char c[2]{};
    for (size_t i = 0; i < 2; i++)
    {
        cin>>c[i];
    }

    int idx[2]{};
    for (size_t i = 0; i < 2; i++)
    {
        idx[i] = FindIdx(str, c[i], (i == 1 ? true : false));
    }
    
    cout<<idx[1] - idx[0];
    
}