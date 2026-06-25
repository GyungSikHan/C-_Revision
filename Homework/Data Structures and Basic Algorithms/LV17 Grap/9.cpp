#include<iostream>
using namespace std;

const int len = 4;
const int dy[8]{-1,-1,0,1,1,1,0,-1};
const int dx[8]{0,1,1,1,0,-1,-1,-1};

struct Point
{
    int y;
    int x;
};

Point InputPigHouse()
{
    Point point{};
    cin>>point.y>>point.x;

    return point;
}

void MakeWall(char (*arr)[len], Point* points)
{
    for (size_t j = 0; j < 3; j++)
    {
        for (size_t i = 0; i < 8; i++)
        {
            int ny = dy[i] + points[j].y;
            int nx = dx[i] + points[j].x;
            
            if(ny<0 || ny >= len || nx < 0 || nx >= len)
            continue;
            if(arr[ny][nx] != '\0')
            continue;
            
            arr[ny][nx] = '@';
        }
    }
}

void Print(char (*arr)[len])
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            if (arr[i][j] == '\0')
                cout<<"_ ";
            else
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    char arr[len][len]{};
    Point points[3];

    for (size_t i = 0; i < 3; i++)
    {
        points[i] = InputPigHouse();
        arr[points[i].y][points[i].x] = '#';
    }
    
    MakeWall(arr, points);
    Print(arr);

}
