#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int y{};
	int x{};

	void operator=(const Point& point)
	{
		y = point.y;
		x = point.x;
	}
};

const int length = 4;
const int row = 3;
const int col = 3;
const int dy[length]{ -1,0,1,0 };
const int dx[length]{ 0,1,0,-1 };

int map[row][col]{};
int visited[row][col]{};

void Print()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << visited[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}

bool Check()
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (visited[i][j] == 0)
				return false;

	return true;
}

void bfs(const Point* points, int len)
{
	queue<Point> qu;
	for (int i = 0; i < len; ++i)
	{
		qu.push({ points[i].y, points[i].x });
		visited[points[i].y][points[i].x] = 1;
	}

	while (!qu.empty())
	{
		Point curr = qu.front();
		qu.pop();

		for (int i = 0; i < length; ++i)
		{
			int ny = curr.y + dy[i];
			int nx = curr.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= row || nx >= col)
				continue;

			if (visited[ny][nx] == 0 || visited[ny][nx] > visited[curr.y][curr.x] + 1)
				visited[ny][nx] = visited[curr.y][curr.x] + 1;
			qu.push({ ny,nx });
		}

		if (Check())
			return;
	}
}

int main()
{
	Point points[2]{};
	for (int i = 0; i < 2; ++i)
		cin >> points[i].y >> points[i].x;
	
	bfs(points, 2);
	Print();
}