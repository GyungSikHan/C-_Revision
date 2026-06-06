#include<iostream>
using namespace std;

int days[4]{};

void Print()
{
    for (size_t i = 0; i < 4; i++)
    {
        cout<<days[i];
    }
    cout<<endl;
}

void Solve(int n, int day)
{
    if(day == 4)
    {
        Print();
        return;
    }

    for (size_t i = 1; i <= n; i++)
    {
        days[day] = i;
        Solve(n, day+1);
        days[day] = 0;
    }
    
}

int main()
{
    int n{};
    cin>>n;

    Solve(n, 0);
}