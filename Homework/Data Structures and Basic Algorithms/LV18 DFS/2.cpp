#include<iostream>
using namespace std;
#define SIZE 8

int mamaco[SIZE][SIZE]
{
    0,1,1,1,0,0,0,
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,
    0,0,0,0,1,1,1,
    0,0,0,0,0,0,1,
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,0
};
char name[SIZE]{ 'A','B', 'H', 'C','D','G','E'};

int main()
{
    char c{};
    cin>>c;

    int idx = -1;
    for (size_t i = 0; i < SIZE; i++)
    {
        if(name[i] == c)
        {
            idx = i;
            break;
        }
    }
    
    if(idx == -1)
    {
        cout<<"Fail"<<endl;
        return 0;
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        if(mamaco[i][idx] == 1)
        {
            for(int j = 0; j < SIZE; j++)
            {
                if(j != idx && mamaco[i][j] == 1)
                    cout<<name[j]<<" ";
            }
            break;
        }
    }
    
}