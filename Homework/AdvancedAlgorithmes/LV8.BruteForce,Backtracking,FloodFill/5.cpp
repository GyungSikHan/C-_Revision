#include <iostream>

using namespace std;

struct Point
{
	int y{};
	int x{};
};

const int length = 4;
const int row = 4;
const int col = 4;
const int dy[length]{-1,0,1,0 };
const int dx[length]{ 0,1,0,-1};

int map[row][col]{};
bool visited[row][col]{};

int dfs(Point curr, int& count)
{
	for (int i = 0; i < length; ++i)
	{
		int ny = curr.y + dy[i];
		int nx = curr.x + dx[i];

		if (ny < 0 || nx < 0 || ny >= row || nx >= col)
			continue;
		if (map[ny][nx] == 0 || visited[ny][nx])
			continue;

		visited[ny][nx] = true;
		count++;
		dfs({ ny,nx }, count);
	}

	return count;
}

int main()
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> map[i][j];

	int ret = -1;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				int cnt = 1;
				visited[i][j] = true;
				dfs({ i,j }, cnt);

				ret = std::max(ret, cnt);
			}
		}
	}

	cout << ret;
}