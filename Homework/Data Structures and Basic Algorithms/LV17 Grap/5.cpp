#include<iostream>
using namespace std;

int dy[4]{-1,0,1,0};
int dx[4]{0,1,0,-1};

int map[4][4]{};

void InputData()
{
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            cin>>map[i][j];  
}

bool Check(int y, int x)
{
    for (size_t i = 0; i < 4; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];

        if(ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
            continue;

        if(map[ny][nx] == 1)
            return true;
    }

    return false;
}

int main()
{
    InputData();
    bool bFlag{};
    for(int i = 0; i < 4; i++)
    {
        bFlag = false;
        for(int j = 0; j < 4; j++)
        {
            if(map[i][j] == 1)
            {
                bFlag = Check(i,j);
            }

            if(bFlag)
                break;
        }
        if(bFlag)
            break;
    }

    cout<<(bFlag ? "위험한 상태!" : "안전한 상태")<<endl;
}