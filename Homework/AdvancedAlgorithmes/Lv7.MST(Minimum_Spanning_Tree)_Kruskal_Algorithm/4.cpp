#include <iostream>
#include <queue>

using namespace std;

const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int map[3][5]
{
	0,0,0,0,1,
	1,0,1,0,0,
	0,0,0,0,1
};
int visited[3][5]{};

struct Point
{
	int y{};
	int x{};
	bool operator==(const Point& point) const
	{
		return (y == point.y) && (x == point.x);
	}
};

int GoToChess(const Point& chess)
{
	queue<Point> qu;
	qu.push({0,0});
	visited[0][0] = 1;

	while (!qu.empty())
	{
		Point curr = qu.front();
		qu.pop();

		if (curr == chess)
			return visited[curr.y][curr.x]-1;

		for (int i = 0; i < 4; ++i)
		{
			int ny = dy[i] + curr.y;
			int nx = dx[i] + curr.x;

			if (nx<0||nx>=5||ny<0||ny>=3)
				continue;
			if (visited[curr.y][curr.x] + 1 < visited[ny][nx])
				continue;
			if (map[ny][nx] == 1)
				continue;

			visited[ny][nx] = visited[curr.y][curr.x] + 1;
			qu.push({ ny,nx });
		}
	}
}

int GoToFriend(const Point& chess, const Point& friends)
{
	queue<Point> qu;
	qu.push(chess);
	visited[chess.y][chess.x] = 1;

	while (!qu.empty())
	{
		Point curr = qu.front();
		qu.pop();

		if (curr == friends)
			return visited[curr.y][curr.x] - 1;

		for (int i = 0; i < 4; ++i)
		{
			int ny = dy[i] + curr.y;
			int nx = dx[i] + curr.x;

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 3)
				continue;
			if (map[ny][nx] == 1)
				continue;
			if (visited[ny][nx] != 0 && visited[curr.y][curr.x] + 1 > visited[ny][nx])
				continue;

			visited[ny][nx] = visited[curr.y][curr.x] + 1;
			qu.push({ ny,nx });
		}
	}
}

int main()
{
	Point chess;
	Point friends;

	cin >> chess.y >> chess.x;
	cin >> friends.y >> friends.x;

	int ret = GoToChess(chess);
	memset(visited, 0, sizeof(visited));
	ret += GoToFriend(chess, friends);

	cout << ret;
}