#include<iostream>
using namespace std;

int visited[3]{};
int cnt;

void Solve(const int* n, int level)
{
    if(level == *n)
    {
        cnt++;
        return;
    }

    for (size_t i = 0; i < 3; i++)
    {
        if(visited[i] + 1 == *n)
            continue;
        
        visited[i]++;
        Solve(n, level+1);
        visited[i]--;
    }   
}

int main()
{
    int n{};
    cin>>n;
    Solve(&n, 0);
    cout<<cnt;
}