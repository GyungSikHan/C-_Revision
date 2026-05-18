#include<iostream>
using namespace std;

void abc(int n)
{
    if(n <= 0)
    {
        return;
    }

    abc(n/2);
    cout<<n<<" ";
}

int main()
{
    int n{};
    cin>>n;

    abc(n);
}