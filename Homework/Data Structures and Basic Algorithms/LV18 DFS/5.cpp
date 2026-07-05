#include<iostream>
using namespace std;

int map[8]{0,3,4,2,4,1,0,3};

void DFS(int idx)
{
    if(idx >= 8)
        return;
    if(map[idx] == 0)
        return;
    cout<<map[idx]<<" ";
    DFS(idx*2);
    DFS(idx*2+1);
}

int main()
{
    int idx1{},idx2{};
    cin>>idx1>>idx2;

    map[idx1] = idx2;
    DFS(1);
}