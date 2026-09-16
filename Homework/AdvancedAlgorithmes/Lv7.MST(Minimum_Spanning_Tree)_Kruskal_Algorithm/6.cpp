#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int row = 4;
const int col = 5;
const int dy[8]{ 0,-1,-1,-1,0,1,1,1 };
const int dx[8]{ -1,-1,0,1,1,1,0,-1 };

int map[row][col]{};
bool visited[row][col]{};

struct Point
{
	int y{};
	int x{};

	bool operator == (const Point& point)const
	{
		return (y == point.y) && (x == point.x);
	}
};

bool Check()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (visited[i][j] == 0)
				return true;
		}
	}
	return false;
}

int BFS(const vector<Point>& v)
{
	queue<Point> temp;
	int cnt{};

	for (const auto& iter : v)
	{
		temp.push(iter);
		visited[iter.y][iter.x] = 1;
	}

	while (Check())
	{
		queue<Point> qu{};
		swap(qu, temp);
		while (!qu.empty())
		{
			Point curr = qu.front();
			qu.pop();

			for (int i = 0; i < 8; ++i)
			{
				int ny = dy[i] + curr.y;
				int nx = dx[i] + curr.x;

				if (nx < 0 || col <= nx || ny < 0 || row <= ny)
					continue;
				if (map[ny][nx] == 1)
					continue;
				if (visited[ny][nx])
					continue;

				visited[ny][nx] = 1;
				temp.push({ ny,nx });
			}
		}
		cnt++;
	}

	return cnt;
}

int main()
{
	vector<Point> v;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				v.push_back({ i,j });
		}
	}

	cout<<BFS(v);
}