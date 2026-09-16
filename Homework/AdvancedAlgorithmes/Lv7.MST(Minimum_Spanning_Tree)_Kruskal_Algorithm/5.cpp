#include<iostream>
#include <queue>

using namespace std;

const int row = 4;
const int col = 6;

const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int map[row][col]{};
bool visited[row][col]{};

struct Point
{
	int y{};
	int x{};

	bool operator==(const Point& point) const
	{
		return (y == point.y) && (x == point.x);
	}
};

int BFS()
{
	queue<Point>qu;
	qu.push({ 0,0 });

	int cnt{};
	while (!qu.empty())
	{
		Point curr = qu.front();
		qu.pop();

		if (map[curr.y][curr.x] == 2)
			cnt++;

		for (int i = 0; i < 4; ++i)
		{
			int ny = dy[i] + curr.y;
			int nx = dx[i] + curr.x;

			if (nx<0||col<= nx||ny<0||row<=ny)
				continue;
			if (map[ny][nx] == 1)
				continue;
			if (visited[ny][nx])
				continue;

			visited[ny][nx] = true;
			qu.push({ ny,nx });
		}
	}

	return cnt;
}

int main()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> map[i][j];
		}
	}	

	cout<<BFS();
}