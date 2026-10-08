#include <iostream>
#include <queue>

using namespace std;

struct Point
{
	int y{};
	int x{};
	int data{};

	bool operator==(const Point& point) const
	{
		return y == point.y && x == point.x;
	}
};

const int row = 5;
const int col = 5;
const int dy[5]{ -1,1,0,0,0 };
const int dx[5]{ 0,0,-1,1,0 };

int map[row][col]
{
	0,0,0,-1,0,
	0,0,0,-1,0,
	-1,-1,0,0,0,
	0,0,-1,0,0,
	0,0,0,0,0
};
vector<vector<int>> elsaVisited(row, vector<int>(col, false));
vector<vector<int>> annaVisited(row, vector<int>(col, false));
Point elsa{};
Point anna{};

Point bfs()
{
	queue<Point>qu;
	qu.push(elsa);
	qu.push(anna);
	int count{};

	while (!qu.empty())
	{
		int y = qu.front().y;
		int x = qu.front().x;
		int data = qu.front().data;
		qu.pop();

		vector<vector<int>> visited;
		if (data == 1)
		{
			visited = elsaVisited;
			elsa.y = y;
			elsa.x = x;
		}
		else if (data == 2)
		{
			visited = annaVisited;
			anna.y = y;
			anna.x = x;
		}

		if (elsa == anna)
		{
			return elsa;
		}

		for (int i = 0; i < 5; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= row || nx >= col)
				continue;
			if (map[ny][nx] == -1)
				continue;

			if (visited[ny][nx] != 0 && visited[ny][nx] < visited[y][x] + 1)
				continue;

			visited[ny][nx] = visited[y][x] + 1;
			qu.push({ ny,nx, data });
		}

		if (data == 1)
			elsaVisited = visited;
		else if (data == 2)
			annaVisited = visited;
	}

	return {};
}

int main()
{
	cin >> elsa.y >> elsa.x;
	cin >> anna.y >> anna.x;
	elsa.data = 1;
	anna.data = 2;
	
	elsaVisited[elsa.y][elsa.x] = 1;
	annaVisited[anna.y][anna.x] = 1;
	Point ret = bfs();
	if (ret.data == 0)
		cout << "fail";
	else
		cout /*<< ret.y << " " << ret.x << " "*/ << elsaVisited[ret.y][ret.x] - 1;
}