#include<iostream>
#include<vector>
using namespace std;

int binaryTree[8]{};
vector<int> v;

void Print()
{
    for(auto iter : v)
        cout<<iter<<" ";
    cout<<endl;
}

void DFS(int idx)
{
    if(idx >= 8)
        return;
    
    if(binaryTree[idx] % 2 == 0)
    {
        v.push_back(binaryTree[idx]);
        Print();
    }
    else if(idx != 1 && binaryTree[idx] % 2 != 0)
        return;

    DFS(idx*2);
    DFS(idx*2+1);
}

int main()
{
    for(int i = 0; i<8; i++)
        cin>>binaryTree[i];
    v.push_back(binaryTree[1]);
    DFS(1);
}