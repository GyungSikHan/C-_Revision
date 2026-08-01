#include <iostream>
using namespace std;

const int MAX = 100;
int n{};
int arr[MAX]{};
int visited[MAX]{};
int cnt{};

void Print()
{
	for (int i = 0; i < level; ++i)
	{
		cout << visited[i] << " ";
	}
	cout << endl;
}

void DFS(int level)
{
	if (level == n)
	{
		//Print();
		cnt++;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == 0)
		{
			visited[i] = level+1;
			DFS(level + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	DFS(0);
	cout << cnt;
}