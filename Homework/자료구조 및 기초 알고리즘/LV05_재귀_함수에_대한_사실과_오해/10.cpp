#include<iostream>
using namespace std;

void abc(char* str, int idx,int len)
{
    if(idx + 1 == len)
    {
        cout<<str[idx]<<endl;
        return;
    }

    abc(str, idx+1, len);
    for (size_t i = idx; i < len; i++)
    {
        cout<<str[i];
    }
    cout<<endl;
    
}

int main()
{
    char str[11]{};
    cin>>str;
    int len{};
    for (size_t i = 0; i < 11; i++)
    {
        if(str[i] == '\0')
            break;
        len++;
    }
    
    abc(str, 0, len);
}