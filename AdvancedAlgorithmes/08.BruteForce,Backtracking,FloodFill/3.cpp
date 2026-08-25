#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int map[4][4]
{
	0,80,40,0,
	80,0,30,60,
	40,30,0,70,
	0,60,70,0
};
bool visited[4]{};

char st{}, en{};
int ret = 987654321;

void DFS(int idx, int end,int sum)
{
	if (idx == end)
	{
		ret = min(ret, sum);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (map[idx][i] == 0 || visited[i] == true)
			continue;

		visited[i] = true;
		DFS(i, end, sum + map[idx][i]);
		visited[i] = false;
	}
}

int makeIndex(char c)
{
	if (c == 'G')
		return 0;
	else if (c == 'N')
		return 1;
	else if (c == 'Y')
		return 2;

	return 3;
}

int main()
{
	int a{}, b{};
	cin >> st >> en;
	a = makeIndex(st);
	b = makeIndex(en);

	visited[a] = true;
	DFS(a, b, 0);

	cout << ret;
}