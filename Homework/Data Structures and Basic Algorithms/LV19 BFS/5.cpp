#include <iostream>
#include <queue>
using namespace std;

vector<int> v;
const int MAX = 6;
int matrix[MAX][MAX]{};

void Print()
{
	for (int iter : v)
		cout << iter << " ";
}

void BFS()
{
	queue<int> qu;
	qu.push(0);

	int ret{};
	while (!qu.empty())
	{
		int curr = qu.front();
		qu.pop();
		if (curr % 2 == 1)
			v.push_back(curr);

		for (int i = 0; i < MAX; ++i)
		{
			if (matrix[curr][i] == 1)
				qu.push(i);
		}
	}

	Print();
}

int main()
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			cin >> matrix[i][j];
	BFS();
}