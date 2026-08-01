#include<iostream>
#include<queue>

using namespace std;

int map[7][7]
{
	{0,1,1,0,0,0,0},
	{0,0,0,1,0,1,0},
	{0,0,0,0,1,1,0},
	{0,0,0,0,0,1,0},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0}
};
int value[10]{ 5,1,35,1,10,70,20 };
int minValue = 987654321;
int path[7] = { value[0], };

struct Node
{
	int num;
	int sum;
	int used[7];
};

queue<Node> qu;

int main()
{
	qu.push({ 0,value[0],{1,0,0,0,0,0,0} });

	while (!qu.empty())
	{
		Node now = qu.front();

		if (now.num == 6 && minValue > now.sum)
			minValue = now.sum;

		for (int i = 0; i < 7; ++i)
		{
			if (map[now.num][i] == 0)
				continue;
			if (now.used[i] == 1)
				continue;

			Node next = now;
			next.num = i;
			next.sum += value[i];
			next.used[i] = 1;

			qu.push(next);
		}
		qu.pop();
	}
	cout << minValue;
}