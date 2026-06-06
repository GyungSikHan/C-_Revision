#include<iostream>
using namespace std;

void abc(char c, int cnt)
{
    if(cnt == 3)
    {
        cout<<c;
        return;
    }

    if(c-1 < 'A')
        c = 'Z';
    abc(c-1, cnt+1);

    cout<<c;
}

void def(char c, int cnt)
{
    if(cnt == 3)
        return;
    
    if(c > 'Z')
        c = 'A';
    cout<<c;
    def(c+1, cnt+1);
}

int main()
{
    char c{};
    cin>>c;
    abc(c,0);
    def(c+1, 0);
}