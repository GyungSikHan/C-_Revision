#include<iostream>
using namespace std;

void Print(char* str, int idx)
{
    if(str[idx] == '\0')
        return;

    for (size_t i = 0; i <= idx; i++)
        cout<<str[i];
    cout<<endl;
    Print(str, idx+1);
}

int main()
{
    char str[256]{};
    cin>>str;

    Print(str, 0);
    
}