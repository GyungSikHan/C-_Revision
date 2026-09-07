#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
vector<vector<int>> v;
vector<vector<int>> visited;
int n{}, m{};
int py{}, px{};

void BFS(const int y, const int x)
{
	int ret{};
	queue<pair<int, int>>qu;
	qu.push({ y,x });
	visited[y][x] = 1;

	while (!qu.empty())
	{
		int cy = qu.front().first;
		int cx = qu.front().second;
		qu.pop();
		ret = visited[cy][cx];
		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (visited[ny][nx] != 0 || v[ny][nx] != 0)
				continue;

			visited[ny][nx] = visited[cy][cx] + 1;
			qu.push({ ny,nx });
		}
	}

	cout << ret-1;
}

int main()
{
	cin >> n >> m;
	v.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];
	cin >> py >> px;

	BFS(py, px);
}