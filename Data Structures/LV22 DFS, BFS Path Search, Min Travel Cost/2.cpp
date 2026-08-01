#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int data;
	int level;
	int path[10]{};
};

int map[5][5]
{
	{0,1,0,1,0},
	{0,0,1,0,1},
	{0,0,0,0,1},
	{0,0,0,0,1},
	{0,0,0,0,0}
};

std::queue<Node>qu;
char value[10] = "BQWER";

int main()
{
	qu.push({ 0,0,{1,0,0,0,0,0,0,0,0,0} });

	while (!qu.empty())
	{
		Node now = qu.front();
		if (value[now.data] == 'R')
		{
			for (int i = 0; i < 5; ++i)
			{
				if (now.path[i] == 1)
					cout << value[i];
			}
			cout << endl;
		}

		for (int i = 0; i < 5; ++i)
		{
			if (map[now.data][i] == 0)
				continue;
			if (now.path[i] == 1)
				continue;

			Node next = now;
			next.data = i;
			next.level = now.level + 1;
			next.path[i] = 1;
			qu.push(next);
		}

		qu.pop();
	}
}