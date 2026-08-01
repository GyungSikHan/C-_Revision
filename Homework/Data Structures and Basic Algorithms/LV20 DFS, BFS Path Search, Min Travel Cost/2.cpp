#include<iostream>
#include <queue>
using namespace std;

int matrix[6][6]
{
	{0,0,1,0,2,0},
	{5,0,3,0,0,0},
	{0,0,0,0,0,7},
	{2,0,0,0,8,0},
	{0,0,9,0,0,0},
	{4,0,0,7,0,0},
};
bool visited[6]{};

void DFS(int index, int sum)
{
	if (index == 6)
		return;

	cout << index << " " << sum << endl;
	for (int i = 0; i < 6; ++i)
	{
		if (matrix[index][i] != 0 && visited[i] == false)
		{
			visited[i] = true;
			DFS(i, sum + matrix[index][i]);
		}
	}
}

int main()
{
	int idx{};
	cin >> idx;

	visited[idx] = 1;
	DFS(idx, 0);
}