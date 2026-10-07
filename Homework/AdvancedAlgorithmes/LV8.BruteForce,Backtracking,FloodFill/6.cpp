#include <iostream>
#include <string>
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
const int col = 5;
const int dy[length]{ -1,0,1,0 };
const int dx[length]{ 0,1,0,-1 };

int arr[10]{};
char map[row][col]{};
bool visited[row][col]{};

int ret = INT_MAX;
Point point{};
void dfs(Point curr, const char c, int count)
{
	if (map[curr.y][curr.x] == c)
	{
		if (count < ret)
		{
			ret = count;
			point = curr;
		}
		return ;
	}

	for (int i = 0; i < length; ++i)
	{
		int ny = curr.y + dy[i];
		int nx = curr.x + dx[i];

		if (ny < 0 || nx < 0 || ny >= row || nx >= col)
			continue;
		if (map[ny][nx] == '#' || visited[ny][nx])
			continue;

		visited[ny][nx] = true;
		dfs({ ny,nx }, c, count + 1);
		visited[ny][nx] = false;
	}
}

int main()
{
	int numCnt{};
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> map[i][j];
			if ('1' <= map[i][j] && map[i][j] <= '9')
				numCnt = std::max(numCnt, map[i][j] - '0');
		}
	}

	int cnt{};
	for (int i = 1; i <= numCnt; ++i)
	{
		ret = INT_MAX;
		memset(visited, false, sizeof(visited));
		if (i == 1)
		{
			visited[0][0] = true;
			dfs({ 0,0 }, '1', 0);
			cnt = ret;
		}
		else
		{
			visited[point.y][point.x] = true;
			char c = *(std::to_string(i).c_str());
			dfs(point, c, 0);
			cnt += ret;
		}
	}

	cout << cnt<<"회";
}