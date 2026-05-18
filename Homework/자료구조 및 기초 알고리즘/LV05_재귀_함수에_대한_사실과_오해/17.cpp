#include<iostream>
using namespace std;

struct Node
{
    int y;
    int x;
};

int arr[4][5]
{
    3,5,4,2,5,
    3,3,3,2,1,
    3,2,6,7,8,
    9,1,1,3,2
};

void Max(int y, int x, int sizeY, int sizeX, int max, Node* point)
{
    if(y + sizeY > 4)
    {
        return;
    }

    int maxValue{};
    for (size_t i = y; i < y+sizeY; i++)
    {
        for (size_t j = x; j < x+sizeX; j++)
        {
            maxValue+=arr[i][j];
        }
    }
    if(max < maxValue)
    {
        max = maxValue;
        point->y = y;
        point->x = x;
    }
    x++;
    if(x+sizeX > 5)
    {
        y++;
        x = 0;
    }
    cout<<max<<" "<<point->y<<","<<point->x<<endl;
    Max(y,x,sizeY,sizeX, max, point);
}

int main()
{
    int sizeY{}, sizeX{};
    cin>>sizeY>>sizeX;

    Node point{};
    Max(0,0, sizeY,sizeX, -1, &point);

    cout<<"("<<point.y<<","<<point.x<<")";

}