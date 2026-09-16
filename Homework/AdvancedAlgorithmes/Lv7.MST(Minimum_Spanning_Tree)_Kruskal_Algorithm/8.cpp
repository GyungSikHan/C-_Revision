#include <iostream>
#include <queue>
using namespace std;

const int length = 8;
int list[length]{ 1,2,3,4,6,7,8,9 };
int matrix[length][length]
{
	0,0,1,1,0,0,1,0,
	0,0,0,0,1,1,0,1,
	1,0,0,0,1,0,1,0,
	1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,
	0,1,0,1,0,0,1,1,
	1,0,1,1,0,1,0,0,
	0,1,0,0,1,1,0,0
};

bool visited[length]{};
int start{};

void BFS(const int& idx)
{
	queue<int> qu;
	qu.push(idx);
	visited[idx] = true;

	while (!qu.empty())
	{
		int curr = qu.front();
		qu.pop();
		cout << list[curr] << " ";
		for (int i = 0; i < length; ++i)
		{
			if (matrix[curr][i] == 0)
				continue;
			if (visited[i])
				continue;

			visited[i] = true;
			qu.push(i);
		}
	}
}

int main()
{
	cin >> start;
	int idx = -1;
	for (int i = 0; i < length; ++i)
	{
		if (list[i] == start)
		{
			idx = i;
			break;
		}
	}
	BFS(idx);
}