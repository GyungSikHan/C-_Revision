#include <iostream>
using namespace std;

int arr[26]{};

void Solve(const char *a, const char* b, const int len)
{
    for (size_t i = 0; i < len; i++)
    {
        if(a[i] == b[i])
            arr[a[i] - 'A']++;
    }
}

char Count()
{
    int max = -1;
    char ret{};
    for (size_t i = 0; i < 26; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
            ret = (char)(i+'A');
        }
    }
    return ret;
}

int main()
{
    char a[4][4]{};
    char b[4][4]
    {
        'A', 'B', 'C', 'D',
        'B', 'B', 'A', 'B',
        'C', 'B', 'A', 'C',
        'B', 'A', 'A', 'A'
    };

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            cin >> a[i][j];

    for (size_t i = 0; i < 4; i++)
    {
        Solve(a[i], b[i], 4);
    }
    cout<<Count();
}