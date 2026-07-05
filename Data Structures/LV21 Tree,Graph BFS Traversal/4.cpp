#include <iostream>
#include <queue>
using namespace std;

char tree[11]{"ABCDEFGHIJ"};
int map[10][10]
{
	{0,1,0,0,0,0,0,0,0,0},
	{1,0,1,1,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,1,0,0,0},
	{0,1,0,0,0,0,0,0,1,0},
	{0,1,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,1,0},
	{0,0,0,0,1,0,0,0,0,1},
	{0,0,0,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,1,0,0},
};
int used[10]{};
struct Node
{
	int num;
	int level;
};

int main()
{
	char c{};
	cin >> c;
	queue<Node> qu;
	for (int i = 0; i < c-'A'; ++i)
	{
		used[i] = 1;
	}
	qu.push(Node{c-'A',0});

	while (!qu.empty())
	{
		Node now = qu.front();
		qu.pop();
		used[now.num] = 1;
		cout << tree[now.num];

		for (int i = 0; i < 10; ++i)
		{
			if (used[i] == 1)
				continue;
			if (map[i][now.num] == 0)
				continue;

			qu.push(Node{ i, now.level + 1 });
		}
	}
}