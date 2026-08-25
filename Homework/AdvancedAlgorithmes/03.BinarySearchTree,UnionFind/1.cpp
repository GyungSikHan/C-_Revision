#include<iostream>

using namespace std;

int cnt{};
char c1{},c2{};

char name[256]{};
int group[256]{};
int n{};
int groupCnt{};

void insert(char a, char b)
{
    if(group[a] == 0)
        name[n++] = a;
    if(group[b] == 0)
        name[n++] = b;

    if(group[a] != 0 && group[b] == 0)
        group[b] = group[a];
    else if(group[a] == 0 && group[b] != 0)
        group[a] = group[b];
    else if(group[a] == 0 && group[b] == 0)
    {
        groupCnt++;
        group[a] = groupCnt;
        group[b] = groupCnt;
    }
    else
    {
        int g = group[a];

        for(int i = 0; i < n; i++)
        {
            if(group[name[i]] != g)
                group[name[i]] = g;
        }
    }
}

bool Cycle()
{
    int g = group[name[0]];
    for (size_t i = 1; i < n; i++)
    {
        if(g != group[name[i]])
            return false;
    }
    return true;
}

int main()
{
    std::cin>>cnt;

    for (size_t i = 0; i < cnt; i++)
    {
        std::cin>>c1>>c2;

        insert(c1, c2);
    }

    std::cout<<(Cycle() ? "발견" : "미발견");
    
}