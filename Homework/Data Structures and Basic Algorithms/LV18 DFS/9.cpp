#include<iostream>
#include<vector>
using namespace std;

int depth{}, branch{};
vector<int> v;

void DFS(int level)
{
    if(level == depth)
    {
        for (size_t i = 0; i < depth; i++)
        {
            cout<<v[i];
            if(i+1 < depth)
                cout<<" ";
        }
        cout<<endl;
        return;
    }

    for (size_t i = 0; i < branch; i++)
    {
        v[level] = i;
        DFS(level+1);
    }
    
}

int main()
{
    cin>>depth>>branch;
    v.resize(depth);
    DFS(0);
}