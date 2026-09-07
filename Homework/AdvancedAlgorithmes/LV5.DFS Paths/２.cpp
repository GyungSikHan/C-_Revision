#include <iostream>

using namespace std;

int n{};
int visited[3]{};
int cnt{};

void Print()
{
	for (int i = 0; i < 3; ++i)
		cout << visited[i] << " ";
	cout << endl;
}

void dfs(int sum, int level)
{
	if (level == 3)
	{
		if (sum == 7)
			cnt++;
		Print();
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (sum+i > 7)
			break;
		visited[level] = i;
		dfs(sum+i, level + 1);
	}
}

int main()
{
	cin >> n;
	dfs(0, 0);
	cout << cnt;
}