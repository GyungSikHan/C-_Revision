#include <iostream>
using namespace std;

const char map[3][4]
{
	'A','B','G','K',
	'T','T','A','B',
	'A','C','C','D'
};

bool Check(const char (*pattern)[2], const int& y, const int& x)
{
	if (y + 2 > 3 || x + 2 > 4)
		return false;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (pattern[i][j] != map[y + i][x + j])
				return false;
		}
	}

	return true;
}

int Solve(const char (*pattern)[2])
{
	int count{};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (Check(pattern, i, j))
				count++;
		}
	}
	return count;
}

int main()
{
	char pattern[2][2]{};

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> pattern[i][j];
		}
	}

	int count = Solve(pattern);
	if (count <= 0)
		cout << "미발견";
	else
		cout << "발견(" << count << ")개";
}