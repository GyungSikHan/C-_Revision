#include<iostream>
using namespace std;

char str[4]{'B','G','T','K'};
char path[256]{};

void Solve(int level, int currLevel)
{
    if(currLevel == level)
    {
        cout<<path<<endl;
        return;
    }

    for (size_t i = 0; i < 4; i++)
    {
        path[currLevel] = str[i];
        Solve(level, currLevel+1);
        path[currLevel] = '\0';
    }
    
}
int main()
{
    int level{};
    cin>>level;
    Solve(level, 0);
}