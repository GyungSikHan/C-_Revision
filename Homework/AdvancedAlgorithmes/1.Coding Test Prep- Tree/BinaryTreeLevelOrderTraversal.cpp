#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int n{};
int arr[2001]{};
string root{};

void PrintTree(int level)
{
	if (arr[level] == -1)
		return;

	cout << arr[level] << " ";
	PrintTree(level * 2);
	PrintTree(level * 2 + 1);
}

void BFS()
{
	queue<int> qu;
	qu.push(1);

	int level = 0;
	while (!qu.empty())
	{
		int now = qu.front();
		qu.pop();
		for (auto iter : {(now * 2), (now * 2 + 1)})
		{
			if (arr[iter] == -1)
				continue;

			qu.push(iter);
		}

		if (now/2 != level)
		{
			level = now / 2 ;
			cout << endl;
		}
		
		cout << arr[now] << " ";
	}
}

int main()
{
	cin >> n;
	memset(arr, -1, sizeof(arr));
	for (int i = 1; i <= n; ++i)
	{
		cin >> root;
		if (root == "null")
			continue;

		arr[i] = stoi(root);
	}

	PrintTree(1);
	cout << endl;
	BFS();
}