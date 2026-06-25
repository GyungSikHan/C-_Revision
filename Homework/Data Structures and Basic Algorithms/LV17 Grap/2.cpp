#include <iostream>
using namespace std;

struct ABC
{
    int data[4];
    int x;
};

void Print(const ABC* node)
{
    for(int i = 0; i < 4; i++)
        cout<<node->data[i]<<" ";
    cout<<endl<<node->x<<endl;
}

int main()
{
    ABC a{{1,2,3,4}, 10};
    ABC b{{7,8,9,10},15};

    ABC* p = &a;
    ABC* g = &b;
    Print(p);
    Print(g);
}