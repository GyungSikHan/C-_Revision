#include<iostream>
using namespace std;

int main()
{
    char str[11]{};
    cin>>str;
    int ret[100]{};

    for (size_t i = 0; i < 10; i++)
    {
        ret[str[i]]++;
    }
    
    int max = ret[0];
    int idx{};
    for (size_t i = 'A'; i <= 'Z'; i++)
    {
        if(max < ret[i])
        {
            max = ret[i];
            idx = i;
        }
    }
    cout<<(char)idx;
}