#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
    char c;
    int data;
};
vector<Node> v;

bool Compare(Node a, Node b)
{
    if(a.c == b.c)
        return a.data < b.data;
    return a.c < b.c;
}

void Print()
{
    for(auto iter : v)
        cout<<iter.c<<" "<<iter.data<<endl;
}

int main()
{
    int size{};
    cin>>size;

    v.resize(size, Node());

    for (size_t i = 0; i < size; i++)
        cin>>v[i].c>>v[i].data;
    
    sort(v.begin(), v.end(), Compare);
    Print();
}