#include <iostream>

int matrix[3][3]
{
	{2,4,3},
	{1,3,7},
	{6,5,6}
};

char path[4]{};
bool check[3]{};

void dfs(int row, int score)
{
	if (row == 3)
	{
		std::cout << "Path: " << path << std::endl;
		std::cout << score << std::endl;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (check[i] == false)
		{
			path[row] = '0' + matrix[row][i];
			check[i] = true;
			dfs(row + 1, score + matrix[row][i]);
			check[i] = false;
			path[row] = 0;
		}
	}
}

int main()
{
	dfs(0,0);
}