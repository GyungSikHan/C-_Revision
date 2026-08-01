#include <iostream>
#include <queue>
using namespace std;

int matrix[6][6]
{
	{0,0,0,0,1,0},
	{1,0,1,0,0,1},
	{1,0,0,1,0,0,},
	{1,1,0,0,0,0},
	{0,1,0,1,0,1},
	{0,0,1,1,0,0}
};
bool visited[6]{};

int main()
{
	int idx{};
	cin >> idx;

	queue<int>qu;
	qu.push(idx);
	visited[idx] = true;

	while (!qu.empty())
	{
		int curr = qu.front();
		qu.pop();

		cout << curr << endl;
		for (int i = 0; i < 6; ++i)
		{
			if (matrix[curr][i] == 0 || visited[i] == true)
				continue;

			visited[i] = true;
			qu.push(i);
		}
	}
}