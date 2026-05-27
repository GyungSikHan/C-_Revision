#include<iostream>
using namespace std;

void InputData(int* input)
{
    cin>>*input;
}

void Solve(const int* input, int level)
{
    cout<<level;
    if(*input == level)
        return;
    for (size_t i = 0; i < 2; i++)
    {
        Solve(input, level+1);
    }
}

int main()
{
    int input{};
    InputData(&input);
    Solve(&input, 0);
}