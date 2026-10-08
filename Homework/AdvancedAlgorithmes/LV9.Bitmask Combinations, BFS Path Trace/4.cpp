#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point
{
	int y{};
	int x{};
};

const int maxCount = 3;
const int row = 7;
const int col = 7;
const int dy[4]{ -1,1,0,0 };
const int dx[4]{ 0,0,-1,1 };

char map[row][col]{};
bool visited[row][col]{};

vector<Point> Squids;
vector<Point> Shremps;

bool bfs(Point curr, char data)
{
	queue<Point> qu;
	qu.push(curr);
	visited[curr.y][curr.x] = true;

	int count{};
	while (!qu.empty() && count < maxCount)
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
			if (visited[ny][nx])
				continue;

			if (data == map[ny][nx] && count < maxCount)
				return false;

			visited[ny][nx] = true;
			qu.push({ ny,nx });
		}

		count++;
	}

	return true;
}

int main()
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == '1')
				Shremps.push_back({ i,j });
			else if (map[i][j] == '2')
				Squids.push_back({ i,j });
		}
	}

	bool bFlag{};

	for (const auto& Shremp : Shremps)
	{
		bFlag = bfs(Shremp, '1');
		if (!bFlag)
			break;
	}
	
	if (!bFlag)
	{
		cout << "fail";
		return 0;
	}
	
	for (const auto& squid : Squids)
	{
		bFlag = bfs(squid, '2');
		if (!bFlag)
			break;
	}

	if (!bFlag)
		cout << "fail";
	else
		cout << "pass";
}

