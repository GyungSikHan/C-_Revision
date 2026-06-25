#include<iostream>
using namespace std;

const int y = 5;
const int x = 4;

void Input(int (*map)[x])
{
    for (size_t i = 0; i < y; i++)
        for (size_t j = 0; j < x; j++)
            cin>>map[i][j];
}

bool CheckBoom(int* map)
{
    int cnt{};
    for (size_t i = 0; i < 4; i++)
        if(map[i] == 1)
            cnt++;
    if(cnt == x)
    {
        memset(map, 0, sizeof(int)*x);
        return true;
    }

    return false;
}

void Down(int* map, int* map2)
{
    for (size_t i = 0; i < x; i++)
    {
        if(map[i] == 1)
            swap(map[i], map2[i]);
    }
}

void Solution(int (*map)[x])
{
    for (size_t i = 0; i < y; i++)   
    {
        if(CheckBoom(map[i]) && i-1 >= 0 && i+1 < y)
        {
            Down(map[i-1], map[i]);
        }
    }
}


int main()
{
    int map[y][x]{};
    Input(map);
    Solution(map);
    cout<<endl;
    for (size_t i = 0; i < y; i++)
    {
        for (size_t j = 0; j < x; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
        
    
}