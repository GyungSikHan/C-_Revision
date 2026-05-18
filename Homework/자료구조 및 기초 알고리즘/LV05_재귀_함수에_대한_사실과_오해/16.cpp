#include <iostream>
using namespace std;

void input(int *data)
{
    for (size_t i = 0; i < 4; i++)
        cin >> data[i];
}

void solve(int *ret, int idx, const int *a, int idx2, const int *b, int idx3)
{
    if(idx == 8)
        return;
    
    if(idx2 == 4)
    {
        ret[idx] = b[idx3];
        solve(ret, idx+1, a, idx2, b, idx3+1);
    }
    else if(idx3 == 4)
    {
        ret[idx] = a[idx2];
        solve(ret, idx+1, a, idx2+1, b, idx3);
    }
    else if (a[idx2] < b[idx3])
    {
        ret[idx] = a[idx2];
        solve(ret,idx+1,a,idx2+1,b,idx3);
    }
    else if (b[idx3] < a[idx2])
    {
        ret[idx] = b[idx3];
        solve(ret,idx+1,a,idx2,b,idx3+1);
    }
    else
    {
        ret[idx] = a[idx2];
        ret[idx+1] = b[idx3];
        solve(ret,idx+2,a,idx2+1,b,idx3+1);
    }
}

int main()
{
    int a[4]{}, b[4]{};
    input(a);
    input(b);

    int ret[8]{};

    solve(ret, 0, a, 0, b, 0);
    for (size_t i = 0; i < 8; i++)
    {
        cout << ret[i] << " ";
    }
}