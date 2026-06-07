#include<iostream>
using namespace std;

void Counting(const int (*levelTable)[2], const int* fruit, int* counts)
{
    for (size_t i = 0; i < 4; i++)
    {
        if(levelTable[i][0] <= *fruit && *fruit <= levelTable[i][1])
        {
            counts[i]++;
        }
    }
}

int main()
{
    int levelTable[4][2]{{10,20}, {30,60}, {100, 150}, {200,300}};
    int counts[4]{};
    int Fruit;

    for (size_t i = 0; i < 6; i++)
    {
        cin>>Fruit;
        Counting(levelTable, &Fruit, counts);
    }   
    
    for (size_t i = 0; i < 4; i++)
    {
        cout<<"lev"<<i<<":"<<counts[i]<<endl;
    }
    
    
}