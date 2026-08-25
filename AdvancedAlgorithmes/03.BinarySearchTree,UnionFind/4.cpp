#include<iostream>

int name[256]{};
int n{};
int group[256]{};
int gCnt{};

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
        gCnt++;
        group[a] = gCnt;
        group[b] = gCnt;
    }    
    else
    {
        int g = group[b];
        for (size_t i = 0; i < n; i++)
        {
            if(group[name[i]] == g)
                group[name[i]] = group[a];
        }
    }
}

int main()
{
    insert('A','B');
    insert('A','C');

    insert('E','Q');
    insert('E','F');

    insert('F','A');
}