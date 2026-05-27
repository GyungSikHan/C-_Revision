#include<iostream>
using namespace std;

int map[3][7]
{
    {0,3,5,4,2,2,3},
    {0,1,3,3,3,4,2},
    {0,5,4,4,2,3,5}
};
char price[6]
{
    '\0','T','P','G','K','C'
};



int Solve(const char* arr, const int* len)
{
    int col = (int)(arr[0] - 'A');
    int row = (int)(arr[1] - '0');

    return map[col][row];
}

int main()
{
    char arr[2]{};
    const int len = 2;
    for (size_t i = 0; i < 2; i++)
        cin>>arr[i];
    
    cout<<price[Solve(arr, &len)];
}