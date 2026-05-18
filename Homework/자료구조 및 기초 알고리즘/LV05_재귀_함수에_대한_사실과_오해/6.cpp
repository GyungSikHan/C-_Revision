#include<iostream>
using namespace std;

void abc(int a, int b)
{
    if(a == b)
    {
        cout<<a<<" ";
        return;
    }

    cout<<a<<" ";
    abc(a+1, b);
    cout<<a<<" ";
}

int main()
{
    int a{},b{};
    cin>>a>>b;
    abc(a,b);
}