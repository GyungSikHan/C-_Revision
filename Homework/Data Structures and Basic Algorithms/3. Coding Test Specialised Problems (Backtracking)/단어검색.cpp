#include<iostream>
using namespace std;

const int maxSize = 6;
const int dy[4]{-1,0,1,0};
const int dx[4]{0,1,0,-1};

int n{}, m{};
char board[maxSize][maxSize]{};
bool visited[maxSize][maxSize]{};
char word[16]{};

bool Solve(int y, int x, int wordSize, int level)
{
    if(wordSize == level)
    {
        return true;;
    }

    bool bFlag{};
    for (size_t i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if(visited[ny][nx])
            continue;
        if(board[ny][nx] != word[level])
            continue;

        visited[ny][nx] = true;
        bFlag = Solve(ny,nx,wordSize, level+1);
        if(bFlag)
            break;
        visited[ny][nx] = false;
    }
    return bFlag;
}

int main()
{
    cin>>n>>m;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            cin>>board[i][j];
    cin>>word;

    bool bFlag{};
    int wordSize = strlen(word);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if(board[i][j] == word[0])
            {
                visited[i][j] = true;
                bFlag = Solve(i,j, wordSize, 1);
                if(bFlag)
                    break;
                visited[i][j] = false;
            }
        }
        if(bFlag)
            break;
    }

    cout<<(bFlag ? "true" : "false")<<endl;
}