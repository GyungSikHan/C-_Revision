#include<iostream>

using namespace std;

int Solve(int branch, int level, int count)
{

    if(count == level)
        return 1;

    int sum = 1;
    for (size_t i = 0; i < branch; i++)
    {
        sum += Solve(branch, level, count+1);
    }
    
    return sum;
}

int main()
{
    int branch{}, level{};
    cin>>branch>>level;   

    cout<<Solve(branch, level, 0);
}