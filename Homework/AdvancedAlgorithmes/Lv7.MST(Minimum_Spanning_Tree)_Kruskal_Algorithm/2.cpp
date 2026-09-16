#include <iostream>
#include <queue>

using namespace std;

const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int map[3][3]{};

struct Point
{
	int y{};
	int x{};
};

void BFS(const Point* point, int size)
{
	queue<Point> qu;
	for (int i = 0; i < size; ++i)
		qu.push(point[i]);

	while (!qu.empty())
	{
		Point curr = qu.front();
		qu.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = dy[i] + curr.y;
			int nx = dx[i] + curr.x;

			if (ny<0||ny>=3||nx<0||nx>=3)
				continue;
			if (map[ny][nx] != 0 && map[ny][nx] < map[curr.y][curr.x] + 1)
				continue;

			map[ny][nx] = map[curr.y][curr.x] + 1;
			qu.push({ ny,nx });
		}
	}
}

void Print()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}
int main()
{
	Point point[2]{};
	for (int i = 0; i < 2; ++i)
	{
		cin >> point[i].y >> point[i].x;
		map[point[i].y][point[i].x] = 1;
	}

	BFS(point, 2);
	Print();
}