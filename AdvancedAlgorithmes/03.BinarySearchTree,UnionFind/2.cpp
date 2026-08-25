#include<iostream>

int bst[256]{};

void insertRescursive(int data, int now)
{
    if(bst[now] == 0)
    {
        bst[now] = data;
        return;
    }
    if(bst[now] > data)
        insertRescursive(data, now*2);
    else
        insertRescursive(data, now*2+1);
}

int main()
{
    insertRescursive(10,1);
    insertRescursive(5,1);
    insertRescursive(15,1);
    insertRescursive(8,1);
}