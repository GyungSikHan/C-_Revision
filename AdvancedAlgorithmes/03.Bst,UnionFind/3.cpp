#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>

int bst[256]{};

void insert(int data)
{
    int idx = 1;
    while (true)
    {
        if(bst[idx]==0)
        {
            bst[idx] = data;
            break;
        }
        else if(bst[idx] > data)
            idx *= 2;
        else
            idx = idx*2+1;    
    }   
}

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

void search(int data)
{
    int idx = 1;
    while (true)
    {
        if(bst[idx] == 0)
        {
            std::cout<<"Not Found\n";
            break;
        }
        if(bst[idx] == data)
        {
            std::cout<<"Found\n";
            break;
        }
        if(bst[idx] > data)
            idx = idx*2;
        else
            idx = idx*2+1;
    }    
}

void searchRecursive(int data, int now)
{
    if(bst[now] == 0)
    {
        std::cout<<"Not Found\n";
        return;
    }
    if(bst[now] == data)
    {
        std::cout<<"Found\n";
        return;
    }
    if(bst[now] > data)
        searchRecursive(data,now*2);
    else
        searchRecursive(data,now*2+1);
}

int main()
{
    // insert(10);
    // insert(5);
    // insert(15);
    // insert(8);
    // insert(3);
    // insert(7);
    // insert(12);

    insertRescursive(3, 1);
    insertRescursive(5, 1);
    insertRescursive(1, 1);
    insertRescursive(2, 1);
    insertRescursive(4, 1);
    insertRescursive(7, 1);
}