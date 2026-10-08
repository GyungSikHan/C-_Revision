#include <iostream>

using namespace std;

const int row = 5;
const int col = 8;
const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int map[row][col]{};
bool visited[row][col]{};

void dfs(int y, int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= row || nx >= col)
			continue;
		if (map[ny][nx] == 0)
			continue;
		if (visited[ny][nx])
			continue;

		visited[ny][nx] = true;
		dfs(ny, nx);
	}
}

int main()
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> map[i][j];

	int count{};
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = true;
				count++;

				dfs(i, j);
			}
		}
	}

	cout << count;
}