#include<iostream>
using namespace std;

const int len = 10;
int ret[10]{};

void Print(int size)
{
    if(size == 0)
        cout<<" ";
    else
    {
        for (size_t i = 0; i < size; i++)
            cout<<ret[i];
    }
    cout<<endl;
}

void Solve(const int* nums, bool* visited, const int& n, int level, int size)
{
    Print(size);
    if(level == n)
        return;

    for (size_t i = level; i < 3; i++)
    {
        ret[size] = nums[i];
        visited[i] = true;
        Solve(nums, visited, n, i+1, size+1);
        visited[i] = false;
        ret[size] = 0;
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
    
    Solve(nums,visited, n ,0, 0);
}