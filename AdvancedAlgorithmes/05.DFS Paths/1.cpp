#include<iostream>

char data[10] = "_ABCDE_G";
int n = 7;

void dfs(int level, int nowIndex)
{
    if(nowIndex > n || data[nowIndex] == '_')
        return;
    
        dfs(level+1, nowIndex*2);
        dfs(level+1, nowIndex*2+1);
        std::cout<<data[nowIndex]<<" ";
}

int main()
{
    dfs(0,1);
}