// Created on iPad.

#include <iostream>
using namespace std;

int main() 
{
    char str[11]{};
    cin>>str;

    int ret[100]{};
    int idx{};
    while(str[idx] != '\0')
    {
        ret[str[idx++]]++;
    }

    for(int i = 'A'; i <= 'Z'; i++)
    {
        if(ret[i])
        {
            cout<<(char)i<<":"<<ret[i]<<endl;
        }
    }
}
