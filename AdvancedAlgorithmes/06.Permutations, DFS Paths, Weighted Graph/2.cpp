#include<iostream>

using namespace std;

char name[5] = {"ABCD"};
int datas[4][4]
{
    0,1,1,0,
    1,0,1,1,
    1,1,0,1,
    0,1,1,0
};

char history[5]{};
int counts{};
int visited[4]{};

bool IsPossible(int now, int select)
{
    if(datas[now][select] == 0)
        return false;
    if(visited[select] == 1)
        return false;
    return true;
}

void dfs(int level, int now)
{
    if(name[now] == 'D')
    {
        counts++;
        cout<<history<<endl;
        return;
    }

    for (size_t i = 0; i < 4; i++)
    {
        if(IsPossible(now, i) == true)
        {
            visited[i] = 1;
            history[level+1] = name[i];
            dfs(level+1, i);
            history[level+1] = 0;
            visited[i] = 0;
        }
    }
    
}

int main()
{
    history[0] = name[0];
    visited[0] = 1;
    dfs(0,0);
}