#include<iostream>
using namespace std;

int dy[4] {-1,0,1,0};
int dx[4]{0,1,0,-1};
int n{},m{};
int map[301][301]{};
bool visited[301][301]{};

bool Move(int y, int x, const int& target)
{
    if(map[y][x] == target)
        return true;

    bool bFlag{};
    for (size_t i = 0; i < 4; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];

        if(ny<0||ny>=n||nx<0||nx>=m)
            continue;
        if(visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        bFlag = Move(ny, nx, target);       
        visited[ny][nx] = false;
    }
    return bFlag;
}

int main()
{
    int target{};

    cin>>n>>m;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            cin>>map[i][j];
    cin>>target;

    cout<<(Move(0,0,target) ? "true":"false");
}