#include <iostream>

using namespace std;

int matrix[6][6]
{
	{0,0,1,1,0,1},
	{0,0,0,1,1,1},
	{0,0,0,0,1,1},
	{0,0,0,0,0,0},
	{1,0,0,0,0,1},
	{0,0,0,0,0,0},
};
bool visited[6]{};

void DFS(int level)
{
	if (level == 6)
	{
		return;
	}

	cout << level << " ";
	for (int i = 0; i < 6; ++i)
	{
		if (matrix[level][i] == 1 && visited[i] == false)
		{
			visited[i] = true;
			DFS(i);
		}
	}
}
int main()
{
	visited[0] = true;
	DFS(0);
}