#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point
{
	int y{};
	int x{};
};

const int length = 8;
const int row = 4;
const int col = 5;
const int dy[length]{ -1,-1,-1,0,1,1,1,0 };
const int dx[length]{ -1,0,1,1,1,0,-1,-1};

int map[row][col]{};
bool visited[row][col]{};

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
		cout << endl<<endl;
}
bool Check()
{
	Print();
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (visited[i][j] == false)
				return true;
	
	return false;
}

int bfs(const vector<Point>& points)
{
	vector<Point> temp;
	queue<Point> que;
	for (const auto& point : points)
	{
		que.push(point);
		visited[point.y][point.x] = true;
	}

	int cnt = 1;
	while (!que.empty())
	{
		queue<Point> qu;
		swap(qu, que);
		while (!qu.empty())
		{
			Point curr = qu.front();
			qu.pop();

			for (int i = 0; i < length; ++i)
			{
				int ny = dy[i] + curr.y;
				int nx = dx[i] + curr.x;

				if (ny < 0 || nx < 0 || ny >= row || nx >= col)
					continue;
				if (visited[ny][nx])
					continue;

				visited[ny][nx] = true;
				que.push({ ny,nx });
			}
		}

		cnt++;
		if (!Check())
			return cnt;
	}

	return -1;
}

int main()
{
	vector<Point> points;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				points.push_back({ i,j });
		}
	}

	cout<<bfs(points);
}