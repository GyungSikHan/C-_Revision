#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <variant>

using namespace std;

struct Point
{
	int y{};
	int x{};
};
struct HOME
{
	int data{};
	int count{};
};

const int row = 4;
const int col = 9;
const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1};

int map[row][col]{};
bool visited[row][col]{};
vector<HOME> ret;

int BFS(int y, int x, int data)
{
	queue<Point> qu;
	qu.push({ y,x });
	int count = 1;

	while (!qu.empty())
	{
		int curry = qu.front().y;
		int currx = qu.front().x;
		qu.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = curry + dy[i];
			int nx = currx + dx[i];
		
			if (ny<0||nx<0||ny>=row||nx>=col)
				continue;
			if (map[ny][nx] != data)
				continue;
			if (visited[ny][nx])
				continue;

			visited[ny][nx] = true;
			qu.push({ ny,nx });
			count++;
		}
	}

	return count;
}

int main()
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> map[i][j];

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (!visited[i][j])
			{
				visited[i][j] = true;
				ret.push_back({map[i][j], 0});
				ret[ret.size()-1].count = BFS(i, j, map[i][j]);
			}
		}
	}

	std::sort(ret.begin(), ret.end(), [](const HOME& a, const HOME& b)
		{
			return a.count > b.count;
		});

	cout << ret[0].count * ret[0].data;
}