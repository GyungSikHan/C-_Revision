#include<iostream>
using namespace std;

#define MAX_SIZE 100

int matrix[MAX_SIZE][MAX_SIZE]{};

void Print(const int size, int y)
{
    if( y == size)
        return;

    cout<<y<<" ";
    for (size_t i = 0; i < size; i++)
    {
        if(matrix[y][i] == 1)
            Print(size, i );
    }
    
}

int main()
{
    int size{};
    cin>>size;

    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            cin>>matrix[i][j];
       
    Print(size,0);
}