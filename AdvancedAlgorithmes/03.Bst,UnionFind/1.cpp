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

int main()
{
    insert(10);
    insert(5);
    insert(15);
    insert(8);
    insert(3);
    insert(7);
    insert(12);
}