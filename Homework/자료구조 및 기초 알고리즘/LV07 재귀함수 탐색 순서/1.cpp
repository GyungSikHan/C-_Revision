#include<iostream>
using namespace std;

char path[2]{};
char str[3]{'A','B','C'};

void Solve(int level)
{
    if(level == 2)
    {
        cout<<path<<endl;
        return; 
    }

    for (size_t i = 0; i < 3; i++)
    {
        path[level] = str[i];
        Solve(level+1);
        path[level] = '\0';
    }
    
}

int main()
{
    Solve(0);
}