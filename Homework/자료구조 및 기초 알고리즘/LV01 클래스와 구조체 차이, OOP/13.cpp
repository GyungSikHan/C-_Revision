#include<iostream>
using namespace std;

struct Point
{
    int y;
    int x;        
};

void GetMin(int (*arr)[3], Point& minPoint)
{
    int temp = 987654321;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(arr[i][j] < temp)
            {
                temp = arr[i][j];
                minPoint.x = j;
                minPoint.y = i;
            }
        }
        
    }
}

void GetMax(int (*arr)[3], Point& maxPoint)
{
    int temp = -987654321;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(arr[i][j] > temp)
            {
                temp = arr[i][j];
                maxPoint.x = j;
                maxPoint.y = i;
            }
        }
        
    }
}

void PrintPoint(Point& point)
{
    cout<<"("<<point.y<<","<<point.x<<")"<<endl;
}
int main()
{    
    int arr[2][3]{};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
    }
    
    Point min{};
    Point max{};
 
    GetMin(arr,min);
    GetMax(arr,max);

    PrintPoint(max);
    PrintPoint(min);
}