#include<iostream>
using namespace std;

char path[256]{};
int cnt{};

int Solve(const char* str, int level)
{
    if(level == 3)
    {
        cnt++;
        if(strcmp(str, path) == 0)
            return cnt;
        return -1;
    }

    int ret{};
    for (size_t i = 0; i < 4; i++)
    {
        path[level] = 'A'+i;
        ret = Solve(str, level+1);
        if(ret != -1)
            return ret;
        path[level] = '\0';
    }

    return -1;
}

int main()
{
    char str[256]{};
    cin>>str;

    cout<<Solve(str, 0)<<"번째";
}