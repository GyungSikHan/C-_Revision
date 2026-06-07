#include<iostream>
using namespace std;

char path[5];
int cnt;

void Solve(const char* str, int level)
{
    if(level == 4)
    {
        cnt++;
        //cout<<path<<endl;
        return;
    }

    for (size_t i = 0; i < 4; i++)
    {
        if(level != 0 && ((str[i] == 'B' && path[level-1] == 'T') || (str[i] == 'T' && path[level-1] == 'B')))
            continue;
        path[level] = str[i];
        Solve(str, level+1);
        path[level] = '\0';
    }
    
}

int main()
{
    char str[4]{};
    for (size_t i = 0; i < 4; i++)
        cin>>str[i];
    Solve(str, 0);
    cout<<cnt;
}