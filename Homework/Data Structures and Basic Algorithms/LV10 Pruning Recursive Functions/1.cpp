#include<iostream>
using namespace std;

char path[3]{};
bool visited[4]{};

void Solve(const char* name, int level)
{
    if(level == 3)
    {
        cout<<path<<endl;
        return;
    }

    for (size_t i = 0; i < 4; i++)
    {
        if(visited[i] == 1)
            continue;

        visited[i] = true;
        path[level] = name[i];
        Solve(name, level+1);
        visited[i] = false;
        path[level] = '\0';
    }
    
}

int main()
{
    char name[4]{};
    for (size_t i = 0; i < 4; i++)
        cin>>name[i];
    Solve(name, 0);
}