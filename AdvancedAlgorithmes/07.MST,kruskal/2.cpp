#include <iostream>
#include <queue>
using namespace std;

const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

struct Node
{
	int Y{};
	int X{};
};

Node point[2]{};
int visited[3][3]{};

void Print()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << visited[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Solution()
{
	queue<Node> qu;
	qu.push(point[0]);
	qu.push(point[1]);

	while (qu.empty() == false)
	{
		int currY = qu.front().Y;
		int currX = qu.front().X;
		qu.pop();

		//Print();

		for (int i = 0; i < 4; ++i)
		{
			int ny = dy[i] + currY;
			int nx = dx[i] + currX;

			if (ny<0 || ny>=3 || nx < 0 || nx >= 3)
				continue;

			if (visited[ny][nx] == 0)
			{
				visited[ny][nx] = visited[currY][currX] + 1;
				qu.push({ ny,nx });
			}
			else if (visited[ny][nx] > visited[currY][currX] + 1)
				visited[ny][nx] = visited[currY][currX] + 1;
		}
	}
}

int main()
{
	for (int i = 0; i < 2; ++i)
	{
		cin >> point[i].Y >> point[i].X;
		visited[point[i].Y][point[i].X] = 1;
	}

	Solution();
	Print();
}