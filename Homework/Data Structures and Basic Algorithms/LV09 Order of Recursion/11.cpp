#include<iostream>
using namespace std;

char path[256]{};

void Dayting(const int* n, int num)
{
    if(num == *n)
    {
        cout<<path<<endl;
        return;
    }

    for (size_t i = 0; i < 2; i++)
    {
        if(i == 0)
            path[num] = 'x';
        else
            path[num] = 'o';

        Dayting(n, num+1);
        path[num] = '\0';
    }
}

int main()
{
    int n{};
    cin>>n;

    Dayting(&n, 0);
}