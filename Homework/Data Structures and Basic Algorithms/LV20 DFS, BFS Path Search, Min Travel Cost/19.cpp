#include <iostream>
using namespace std;

const int MAX = 10;

struct Node
{
	int data = -1;
	int y;
	int x;
};
int n{}, m{};
int map[MAX][MAX]{};
Node ret[3]{};


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];

	for (int i = 0; i < 3; ++i)
	{
		Node temp{};
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < m; ++x)
			{
				if (temp.data < map[y][x])
				{
					temp.data = map[y][x];
					temp.y = y;
					temp.x = x;
				}
			}
		}
		map[temp.y][temp.x] = -1;
		ret[i] = temp;
	}

	for (int i = 0; i < 3; ++i)
	{
		cout << ret[i].data << "(" << ret[i].y << "," << ret[i].x << ")\n";
	}
}