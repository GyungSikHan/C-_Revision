#include<iostream>
using namespace std;

int cnt;
int ret[4];

void Solve(const int* arr, int level)
{
    if(level == 4)
    {
        cnt++;
        return;
    }
    for (size_t i = 0; i < 5; i++)
    {
        if(level != 0 && std::abs(ret[level-1] - arr[i]) > 3)
            continue;

        ret[level] = arr[i];
        Solve(arr, level+1);
        ret[level] = 0;
    }
}

int main()
{
    int arr[5]{};
    for (size_t i = 0; i < 5; i++)
    {
        cin>>arr[i];
    }
    
    Solve(arr, 0);
    cout<<cnt;
}