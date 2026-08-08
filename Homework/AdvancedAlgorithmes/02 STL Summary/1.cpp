#include<iostream>
#include <algorithm>
using namespace std;

struct SET
{
    int data;
    char c;
};

int n{};
SET* s{};

bool compare(const SET& a, const SET& b)
{
    if(a.data == b.data)
        return a.c < b.c;

    return a.data < b.data;
}

int main()
{
    cin>>n;
    s = new SET[n];

    for (int i = 0; i < n; i++)
        cin>>s[i].data>>s[i].c;
    
    std::sort(s, s+n, compare);

    for(int i = 0; i < n; i++)
        cout<<s[i].data<<" "<<s[i].c<<endl;

    delete[] s;
    s = nullptr;

    return 0;
}