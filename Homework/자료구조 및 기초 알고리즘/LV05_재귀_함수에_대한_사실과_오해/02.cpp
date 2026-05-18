#include<iostream>
using namespace std;

void Count(int n)
{
    if(n == 0)
    {
        cout<<n<<" ";
        return;
    }
    
    cout<<n<<" ";
    Count(n-1);
    cout<<n<<" ";
}

int main()
{
    int n{};
    cin>>n;
    Count(n);
}