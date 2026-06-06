#include<iostream>
using namespace std;

char path[9]{};

void Solve(int n, int l, int r)
{
    if(path[0] == ')' || r > l)
        return;
    if((r+l)/2 == n)
    {
        if(r != l)
            return;

        cout<<path<<" ";
        return;
    }
    
    for (size_t i = 0; i < 2; i++)
    {
        if(i == 0)
        { 
            path[l+r] = '(';
            Solve(n,l+1, r);
        }
        else
        {
            path[l+r] = ')';
            Solve(n,l, r+1);
        }
        path[l+r] = '\0';
    }
}

int main()
{
    int n{};
    cin>>n;

    Solve(n, 0,0);
}