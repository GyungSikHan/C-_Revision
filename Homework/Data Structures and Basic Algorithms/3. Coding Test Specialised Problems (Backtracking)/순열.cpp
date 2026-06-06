#include<iostream>
using namespace std;

const int len = 6;
int ret[len]{-11};

void Print(const int& n)
{
    for (size_t i = 0; i < n; i++)
        cout<<ret[i]<<" ";
    cout<<endl;
}

void Solve(const int* nums, bool* visited, const int& n, int level)
{
    if(n == level)
    {
        Print(n);
        return;
    }

    for (size_t i = 0; i < n; i++)
    {
        if(visited[i] == true)
            continue;
        visited[i] = true;
        ret[level] = nums[i];
        Solve(nums, visited, n, level+1);
        ret[level] = -11;
        visited[i] = false;
    }
    
}

int main()
{
    int n{};
    int nums[len]{};
    bool visited[len]{};
    cin>>n;
    for (size_t i = 0; i < n; i++)
        cin>>nums[i];
    
    Solve(nums, visited, n, 0);
}