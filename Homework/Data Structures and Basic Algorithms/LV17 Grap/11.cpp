#include<iostream>
#include<queue>
using namespace std;

const int len = 4;
const int dy[4]{-1,0,1,0};
const int dx[4]{0,1,0,-1};

struct Point
{
    int y;
    int x;
};

Point Input()
{
    Point input{};
    cin>>input.y>>input.x;

    return input;
}

void Solution(int (*arr)[len], bool (*visited)[len], Point point)
{
    arr[point.y][point.x] = 1;
    visited[point.y][point.x] = 1;
    queue<Point> qu;
    qu.push(point);

    while (!qu.empty())
    {
        int y = qu.front().y;
        int x = qu.front().x;
        qu.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int ny = dy[i]+y;
            int nx = dx[i]+x;

            if(ny<0||ny>=len||nx<0||nx>=len)
                continue;
            if(visited[ny][nx] != 0)
                continue;

            arr[ny][nx] = arr[y][x] + 1;
            visited[ny][nx] = true;
            qu.push({ny,nx});
        }   
    }   
}

void Print(int (*arr)[len])
{   
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[4][4]{};
    bool visited[4][4]{};
    Point input{};
    input = Input();
    Solution(arr, visited, input);
    Print(arr);

}