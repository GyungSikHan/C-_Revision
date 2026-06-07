#include<iostream>
using namespace std;

void Solve(int len)
{
    if(len == 1)
    {
        cout<<len<<" ";
        return;
    }

    cout<<len<<" ";
    Solve(len-1);
    cout<<len<<" ";
}

int main()
{
    char str[256]{};
    cin>>str;

    int len = strlen(str);
    Solve(len);
}