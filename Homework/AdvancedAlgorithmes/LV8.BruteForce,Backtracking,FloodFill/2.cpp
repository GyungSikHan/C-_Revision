#include <iostream>

using namespace std;

const int row = 3;
const int col = 5;
const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int map[row][col]
{
	0,0,0,0,1,
	1,0,1,0,0,
	0,0,0,0,1
};
bool visited[row][col]{};
int ret = INT_MAX;

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

void dfs(int y, int x, const int arriveY, const int arriveX, int count)
{
	if (y == arriveY && x == arriveX)
	{
		ret = std::min(ret, count);
		//cout << ret << endl;
		//Print();
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= row || nx >= col)
			continue;
		if (map[ny][nx] == 1 || visited[ny][nx])
			continue;

		visited[ny][nx] = true;
		dfs(ny, nx, arriveY, arriveX, count+1);
		visited[ny][nx] = false;
	}
}

int main()
{
	int CheeseY{}, CheeseX{}, friendY{}, friendX{};
	cin >> CheeseY >> CheeseX >> friendY >> friendX;

	visited[0][0] = true;
	dfs(0, 0, CheeseY, CheeseX, 0);
	int temp = ret;

	memset(visited, false, sizeof(visited));
	visited[CheeseY][CheeseX] = true;
	ret = INT_MAX;
	dfs(CheeseY, CheeseX, friendY, friendX, 0);
	ret += temp;

	cout << ret;
}