#include<iostream>
#include<algorithm>

char str[5]="ABCD";
int map[4][4]
{
    0,10,60,0,
    10,0,20,40,
    60,20,0,50,
    0,40,50,0
};
bool visited[4]{};
int ret=987654321;

void dfs(int level, int sum)
{
    if(str[level] == 'D')
    {
        if(ret > sum)
            ret = sum;
        return;
    }

    for (size_t i = 0; i < 4; i++)
    {
        if(map[level][i] == 0 || visited[i] == true)
            continue;
        
        visited[i] = true;
        dfs(i, sum + map[level][i]);
        visited[i] = false;
    }
    
}

int main()
{
    visited[0] = true;
    dfs(0, 0);

    std::cout<<ret;
}


//학교 다니면서 했던 과제물들 전부 모아 오기 -> 이력서 쓰기 전까지