#include<iostream>
using namespace std;

bool check(char* str, int len, int idx, int idx2)
{
    if(idx2 == len)
        return true;
    
    if(str[idx] != str[idx2])
        return false;
    return check(str,len, idx+1, idx2+1);
}

int main()
{
    char str[11]{};
    cin>>str;
    int len{};
    while (str[len] != '\0')
        len++;

    if(check(str, len,0, len/2))
        cout<<"동일한문장";
    else   
        cout<<"다른문장";
    
    
}