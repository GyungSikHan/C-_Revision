#include <iostream>
#include <vector>
using namespace std;

const int length = 4;
const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

struct Point
{
	int y{};
	int x{};
};
int map[length][length]{};
bool visited[length][length]{};

void DFS(int y, int x, int& count)
{
	int cnt = count;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || length <= nx || ny < 0 || length <= ny)
			continue;
		if (map[ny][nx] == 0)
			continue;
		if (visited[ny][nx])
			continue;

		visited[ny][nx] = true;
		count++;
		DFS(ny, nx, count);
	}

}

int main()
{
	vector<Point> v;
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				v.push_back({ i,j });
		}
	}

	int ret{};
	for (const auto& value : v)
	{
		int cnt{};
		if (!visited[value.y][value.x])
		{
			DFS(value.y, value.x, cnt);
			ret = max(ret, cnt);	
		}
	}

	cout << ret;
}

