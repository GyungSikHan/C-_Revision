#include <iostream>

using namespace std;

const int length = 4;
const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int map[length][length]
{
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	0,1,1,0
};
int visited[length][length]{};

struct Point
{
	int y{};
	int x{};
	bool operator==(const Point point)const
	{
		return (y == point.y) && (x == point.x);
	}
};

void DFS(const Point& curr, const Point& end)
{
	if (curr == end)
		return;

	for (int i = 0; i < 4; ++i)
	{
		int ny = dy[i] + curr.y;
		int nx = dx[i] + curr.x;

		if (nx < 0 || length <= nx || ny < 0 || length <= ny)
			continue;
		if (map[ny][nx] == 1)
			continue;
		if (visited[ny][nx] != 0 && visited[ny][nx] < visited[curr.y][curr.x] + 1)
			continue;

		visited[ny][nx] = visited[curr.y][curr.x] + 1;
		DFS({ ny,nx }, end);
	}
}

int main()
{
	Point point[2]{};

	for (int i = 0; i < 2; ++i)
		cin >> point[i].y >> point[i].x;

	visited[point[0].y][point[0].x] = 1;
	DFS(point[0], point[1]);

	cout << visited[point[1].y][point[1].x] - 1;
}