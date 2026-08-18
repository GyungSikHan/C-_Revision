#include<iostream>

char parent[1000]{};

char getParent(char x)
{
    if(parent[x] == 0)
        return x;

    int ret = getParent(parent[x]);
    parent[x] = ret;

    return ret;
}

void insert(char ch1, char ch2)
{
    int a = getParent(ch1);
    int b = getParent(ch2);

    if(a != b)
        parent[b] = a;
}

int main()
{
    insert('A', 'G');
    insert('H', 'C');
    insert('A', 'H');
    insert('F', 'D');
    insert('A', 'F');
}