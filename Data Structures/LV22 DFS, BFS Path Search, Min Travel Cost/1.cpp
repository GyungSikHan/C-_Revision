#include <iostream>
#include <queue>

char value[10] = "ZADCEB";
int visited[10]{};
int map[6][6]
{
	{0,1,1,1,0,0},
	{1,0,0,1,0,1},
	{1,0,0,1,0,0},
	{1,1,1,0,1,1},
	{0,0,0,1,0,1},
	{0,1,0,1,1,0}
};

int cnt{};
char path[10]{};
bool flag{};

void dfs(int now, int level)
{
	if (now == 5)
	{
		flag = true;
		cnt++;
		std::cout << path << std::endl;
		return;
	}

	for (int i = 0; i < 6; ++i)
	{
		if (map[now][i] == 1&& value[i] == 0)
		{
			visited[i] = 1;
			path[level + 1] = value[i];
			dfs(i, level + 1);
			visited[i] = 0;
			path[level + 1] = 0;
		}
	}
}

int main()
{
	visited[0] = 1;
	path[0] = value[0];
	dfs(0,0);
}