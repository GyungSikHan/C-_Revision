#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n{};
vector<vector<int>> v;
vector<int> visited;

bool Cycle(int idx)
{
    for (size_t i = 0; i < n; i++)
    {
        if(v[idx][i] == 0 || visited[i] == idx)
         continue;
        if(visited[i] != -1)
            return true;

        visited[idx] = i;
        return Cycle(i);
    }
    
    return false;
}

int main()
{
    cin>>n;
    v.assign(n, vector<int>(n, 0));
    visited.assign(n, -1);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            cin>>v[i][j];
    
    bool ret = Cycle(0);
    if(ret == true)
        std::cout<<"cycle 발견";
    else 
        std::cout<<"미발견"<<endl;
}