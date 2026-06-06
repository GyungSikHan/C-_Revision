#include<iostream>
using namespace std;

void InputData(int* level, int* branch)
{
    cin>>*level>>*branch;
}

void Solve(int level, const int* branch)
{
    if(level == 0 )
        return;
    for (size_t i = 0; i < *branch; i++)
        Solve(level-1, branch);
}
int main()
{
    int level{};
    int branch{};

    InputData(&level,&branch);
    Solve(level, &branch);
}  