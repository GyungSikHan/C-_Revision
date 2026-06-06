#include<iostream>
using namespace std;

void BBQ(int n)
{
    if(n == 2)
        return;
    BBQ(n+1);
}

int main()
{
    BBQ(0);
}