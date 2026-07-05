#include <iostream>
#include <queue>
using namespace std;

int map[5][5]
{
	{0,1,0,1,1,},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{0,0,0,0,1},
	{0,0,0,0,0},
};

char value[6] = "EBRAY";

struct Node
{
	int num;
	int level;
};
queue<Node> qu;
int used[6]{};

int main()
{
	qu.push(Node{});
	used[0] = 1;

	while (!qu.empty())
	{
		Node now = qu.front();
		qu.pop();

		cout << value[now.num] << endl;
		cout << "---------------" << endl;

		for (int i = 0; i < 5; ++i)
		{
			if (used[i] == 1)
				continue;
			if (map[now.num][i] == 0)
				continue;

			used[i] = 1;
			qu.push(Node{ i,now.level + 1 });
		}
	}
}