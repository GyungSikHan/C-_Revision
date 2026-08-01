#include <iostream>
using namespace std;

const int MAX = 6;
int map[MAX][MAX]{};
char arr[MAX]{ 'A','B','C','D','E','F' };
char visited[MAX]{};

void DFS(int level, int idx)
{
	if (level == MAX)
		return;

	bool bFlag{};
	for (int i = 0; i < MAX; ++i)
	{
		if (map[idx][i] == 1)
		{
			bFlag = true;
			visited[level]= arr[i];
			DFS(level+1, i);
			visited[level] = '\0';
		}
	}

	if (bFlag)
		return;
	int i{};
	while (visited[i] != '\0')
	{
		cout << visited[i] << " ";
		i++;
	}
	cout << endl;
}

int main()
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			cin >> map[i][j];

	visited[0] = arr[0];
	DFS(1,0);
}