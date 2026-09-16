#include <iostream>
#include <queue>
using namespace std;

const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int map[4][4]
{
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	1,0,1,0
};
int visited[4][4]{};

struct Point
{
	int y{};
	int x{};

	bool operator==(const Point& data) const
	{
		return (y == data.y) && (x == data.x);
	}
};

void BFS(const Point& start, const Point& end)
{
	queue<Point> qu;
	qu.push(start);
	visited[start.y][start.x] = 1;

	while (!qu.empty())
	{
		Point curr = qu.front();
		qu.pop();

		if (curr == end)
			break;

		for (int i = 0; i < 4; ++i)
		{
			int ny = dy[i] + curr.y;
			int nx = dx[i] + curr.x;

			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
				continue;
			if (map[ny][nx] == 1)
				continue;
			if (visited[ny][nx] != 0)
				continue;

			visited[ny][nx] = visited[curr.y][curr.x]+1;
			qu.push({ ny,nx });
		}
	}
}

int main()
{
	Point start{};
	Point end{};

	cin >> start.y >> start.x;
	cin >> end.y >> end.x;
	BFS(start, end);

	cout << visited[end.y][end.x] - 1;
}