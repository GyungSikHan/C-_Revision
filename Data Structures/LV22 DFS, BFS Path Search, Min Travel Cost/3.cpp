#include <iostream>
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
int visited[7]{ 1, };
int minValue = 987654321;
int path[7] = {value[0],};

void dfs(int now, int sum, int level)
{
	if (now == 6)
	{
		if (minValue > sum)
			minValue = sum;

		return;
	}

	for (int i = 0; i < 7; ++i)
	{
		if (map[now][i] == 0)
			continue;
		if (visited[i] == 1)
			continue;

		visited[i] = 1;
		dfs(i, sum + value[i], level + 1);
		visited[i] = 0;
	}
}

int main()
{
	dfs(0, value[0], 0);
	cout << minValue << endl;
}