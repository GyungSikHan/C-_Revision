#include <iostream>
#include <vector>

using namespace std;

void DFS(const vector<int>& v, int level)
{
    if(v.size() <= level || v[level] == -1)
        return;

    DFS(v, level*2);
    cout<<v[level]<<" ";
    DFS(v,level*2+1);
}

int main()
{
    int n{};
    string str{};
    cin>>n;
    vector<int> v(n+1, -1);
    for (size_t i = 1; i <= n; i++)
    {
        cin>>str;
        if(str != "null")
            v[i] = stoi(str);
    }
    
    DFS(v, 1);
}