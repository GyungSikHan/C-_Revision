#include<iostream>

using namespace std;

int dy[4]{-1,0,1,0};
int dx[4]{0,1,0,-1};

int map[3][3]
{
    0,0,0,
    1,0,1,
    0,0,0
};
bool visited[3][3];

void dfs(int level, int nowX, int nowY)
{
    if(nowY == 2 && nowX == 0)
    {
        cout<<level<<"번만에 도착"<<endl;
        return;
    }

    for (size_t i = 0; i < 4; i++)
    {
        int nx = nowX+dx[i];
        int ny = nowY+dy[i];

        if(nx<0||nx>=3||ny<0||ny>=3)
            continue;
        if(visited[ny][nx])
            continue;
        if(map[ny][nx] != 0)
            continue;

        visited[ny][nx] = true;
        dfs(level+1, nx,ny);
        visited[ny][nx] = false;

    }
    
}

int main()
{
    visited[0][0] = true;
    dfs(0,0,0);
}