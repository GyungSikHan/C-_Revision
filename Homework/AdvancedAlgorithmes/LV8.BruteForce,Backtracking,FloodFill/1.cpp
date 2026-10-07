#include <iostream>

using namespace std;

const int length = 4;
const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int map[length][length]
{
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	1,0,1,0
};
int visited[length][length]{};
int ret = 987654321;

void dfs(const int endY, const int endX, int y, int x, int count)
{
	if (y == endY && x == endX)
	{
		ret = std::min(ret, count);
		return;
	}

	for (int i = 0; i < length; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<0 || nx<0||ny>=length||nx>=length)
			continue;
		if (map[ny][nx] == 1 || visited[ny][nx])
			continue;

		visited[ny][nx] = true;
		dfs(endY, endX, ny, nx, count + 1);
		visited[ny][nx] = false;
	}
}

int main()
{
	int startY{}, startX{}, endY{}, endX{};
	cin >> startY >> startX >> endY >> endX;

	dfs(endY, endX, startY, startX, 0);

	cout << ret<<"회";
}