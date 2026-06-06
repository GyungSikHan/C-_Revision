#include<iostream>
using namespace std;

const int len = 5;
char path[len]{};
void Solve(char* arr,int n, int level)
{
    if(level == n)
    {
        cout<<path<<" ";
        return;
    }

    for (size_t i = 0; i < 3; i++)
    {
        int temp = (int)(arr[level] - '2') * 3;
        path[level] = (char)('a'+(i+temp));
        Solve(arr, n ,level + 1);
        path[level] = '\0';
    }
}

int main()
{
    char arr[len]{};
    cin>>arr;
    int n = strlen(arr);

    Solve(arr,n,0);
}