#include<iostream>
using namespace std;

void abc(int n, int cnt)
{
    if(cnt == 3)
    {
        cout<<n<<" ";
        return;
    }

    abc(n+2, cnt+1);
    cout<<n<<" ";
}

int main()
{
    int n{};
    cin>>n;

    abc(n, 0);
}