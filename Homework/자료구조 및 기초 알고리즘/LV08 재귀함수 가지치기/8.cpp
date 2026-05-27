#include<iostream>
using namespace std;

struct Point
{
    int y;
    int x;
};
char map[3][4];

bool Solve(const Point* point, const int len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(j == point[i].y)
                continue;

            if(map[j][point[i].x] == '#')
                return false;
        }
        
        for (size_t j = 0; j < 4; j++)
        {
            if(j == point[i].x)
                continue;
            
            if(map[point[i].y][j] == '#')
                return false;
        }
    }
    return true;
}

int main()
{
    Point point[3]{};
    for (size_t i = 0; i < 3; i++)
    {
        cin>>point[i].y>>point[i].x;
        map[point[i].y][point[i].x] = '#';
    }

    if(Solve(point, 3))
        cout<<"safe";
    else
        cout<<"Not safe";
}