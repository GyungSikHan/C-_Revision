#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int y{};
	int x{};
};

const int row = 4;
const int col = 6;
const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int map[row][col]{};
bool visited[row][col]{};

void bfs(int* count)
{
	queue<Point> qu;
	qu.push({ 0,0 });

	while (!qu.empty())
	{
		int y = qu.front().y;
		int x = qu.front().x;
		qu.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= row || nx >= col)
				continue;
			if (map[ny][nx] == 1 || visited[ny][nx])
				continue;

			if (map[ny][nx] == 2)
				(*count)++;
			visited[ny][nx] = true;
			qu.push({ ny,nx });
		}
	}

}

int main()
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> map[i][j];
	int ret{};
	bfs(&ret);

	cout << ret;
}