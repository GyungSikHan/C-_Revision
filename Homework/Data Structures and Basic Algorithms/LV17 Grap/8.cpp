#include<iostream>
using namespace std;

const int y =3;
const int x = 3;

struct Point
{
    int pY;
    int pX;
    int data;
};

void InputArray(int(*arr)[x])
{
    for (size_t i = 0; i < y; i++)
        for (size_t j = 0; j < x; j++)
            cin>>arr[i][j];
}

Point SerchMax(int (*arr)[x])
{
    Point ret{-1,-1,-987654321};

    for (size_t i = 0; i < y; i++)
    {
        for (size_t j = 0; j < x; j++)
        {
            if(arr[i][j] > ret.data)
            {
                ret.data = arr[i][j];
                ret.pY = i;
                ret.pX = j;
            }
        }
    }

    arr[ret.pY][ret.pX] = -987654321;

    return ret;
};

void Print(Point& point)
{
    cout<<point.data<<"("<<point.pY<<","<<point.pX<<")"<<endl;
}

int main()
{
    int arr[y][x];
    InputArray(arr);
    
    Point Max1 = SerchMax(arr);
    Point Max2= SerchMax(arr);

    cout<<"첫번째:";
    Print(Max1);
    cout<<"두번째:";
    Print(Max2);
}