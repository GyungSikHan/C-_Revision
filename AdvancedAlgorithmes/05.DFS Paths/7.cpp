#include <iostream>
using namespace std;

const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };
const int length = 3;
int map[length][length]
{
	1,1,1,
	0,1,0,
	1,1,1
};
int visited[length][length]{};

void Print()
{
	for (int i = 0; i < length; ++i)
		for (int j = 0; j < length; ++j)
		{
			if (visited[i][j] == 1)
				cout << i << " " << j << endl;
			
		}
}

void dfs(int y, int x, int level)
{
	if (y == 2 && x == 2)
	{
		Print();
		cout << "도착" << endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (nx<0 || nx >= length || ny <0 || ny>=length)
			continue;
		if (map[ny][nx] == 0 || visited[ny][nx] == 1)
			continue;

		visited[ny][nx] = 1;
		dfs(ny, nx, level + 1);
		visited[ny][nx] = 0;
	}
}

int main()
{
	visited[0][0] = 1;
	dfs(0,0,0);
}
