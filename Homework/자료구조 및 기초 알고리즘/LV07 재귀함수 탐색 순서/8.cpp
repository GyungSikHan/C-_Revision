#include <iostream>
using namespace std;

struct MinMax
{
    int min = 987654321;
    int max = -987654321;
};

int arr[3][2][2]
{
    {
        2, 4,
        1, 5
    },
    {
        2, 3,
        3, 6
    },
    {
        7, 3,
        1, 5
    }
};

void Solve(MinMax* ret, const int* i)
{
    for (size_t j = 0; j < 2; j++)
    {
        for (size_t k = 0; k < 2; k++)
        {
            if(arr[*i][j][k] < ret->min)
                ret->min = arr[*i][j][k];
            if(ret->max < arr[*i][j][j])
                ret->max = arr[*i][j][k];
        }
    }
}

int main()
{
    int n{};
    MinMax ret{};
    cin >> n;

    Solve(&ret, &n);

    cout<<"MAX="<<ret.max<<endl;
    cout<<"MIN="<<ret.min<<endl;
}