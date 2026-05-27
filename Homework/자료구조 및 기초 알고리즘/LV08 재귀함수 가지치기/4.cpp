#include<iostream>
using namespace std;

char Santa[5]{'B','T','S','K','R'};
char path[256]{};
int visited[26];
int cnt;

void Solve(const int* n, int level)
{
    if(level == *n)
    {
        if(visited['S' - 'A'] == 1)
        {
            cout<<path<<endl;
            cnt++;
        }
        return;
    }

    for (size_t i = 0; i < 5; i++)
    {
        if(visited[Santa[i]-'A'] != 0)
            continue;
        path[level] = Santa[i];
        visited[Santa[i] - 'A'] = 1;
        Solve(n, level+1);
        visited[Santa[i] - 'A'] = 0;
        path[level] = '\0';
    }
    
}

int main()
{
    int n{};
    cin>>n;

    Solve(&n,0);
    cout<<cnt;
}