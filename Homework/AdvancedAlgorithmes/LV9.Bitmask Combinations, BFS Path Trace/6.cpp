#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int y{};
	int x{};
	int data{};
};

const int length = 4;
const int row = 8;
const int col = 9;
const int dy[length]{ -1,1,0,0 };
const int dx[length]{ 0,0,-1,1 };

char map[row][col]{};
int floodFill[row][col]{};

vector<vector<Point>> v(2);

void FloodFill(Point curr, int data)
{
	queue<Point> qu;
	qu.push(curr);		
	floodFill[curr.y][curr.x] = data;
	v[data - 1].push_back({ curr.y,curr.x ,data});

	while (!qu.empty())
	{
		int y = qu.front().y;
		int x = qu.front().x;
		
		qu.pop();

		for (int i = 0; i < length; ++i)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= row || nx >= col)
				continue;
			if (map[ny][nx] != '#')
				continue;
			if (floodFill[ny][nx] != 0)
				continue;

			v[data - 1].push_back({ ny,nx ,data});
			floodFill[ny][nx] = data;
			qu.push({ ny,nx });
		}
	}
}

int bfs()
{
	queue<Point> qu;
	for (const auto& iter : v[0])
		qu.push(iter);
	int visited[row][col]{};

	while (!qu.empty())
	{
		int y = qu.front().y;
		int x = qu.front().x;
		int data = qu.front().data;
		qu.pop();

		if (map[y][x] == '#' && floodFill[y][x] != data)
			return visited[y][x];

		for (int i = 0; i < length; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= row || nx >= col)
				continue;
			if (map[ny][nx] == '#' && data == floodFill[ny][nx])
				continue;
			if (visited[ny][nx] != 0 && visited[ny][nx] < visited[y][x] + 1)
				continue;

			visited[ny][nx] = visited[y][x] + 1;
			qu.push({ ny,nx,data });
		}
	}

	return -1;
}

int main()
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> map[i][j];

	int data = 1;
	
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (map[i][j] == '#' && floodFill[i][j] == 0)
				FloodFill({ i,j ,0 }, data++);

	int ret = bfs();

	if (ret == -1)
		cout << "fail";
	else
		cout << ret-1;
}

