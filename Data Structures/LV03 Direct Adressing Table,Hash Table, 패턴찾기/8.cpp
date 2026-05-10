#include <iostream>
using namespace std;

int map[5][5]
{
	1,3,5,1,5,
	3,7,9,5,8,
	4,5,3,9,7,
	2,7,6,1,9,
	1,6,2,3,8
};

int pattern[2][2]
{
	3,5,
	7,9
};

int IsPattern(int dy, int dx)
{
	for (int y = 0; y < 2; ++y)
	{
		for (int x = 0; x < 2; ++x)
		{
			if (map[dy + y][dx + x] != pattern[y][x])
				return 0;
		}
	}
	return 1;
}

int main()
{
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			int ret = IsPattern(y,x);
			if (ret)
			{
				cout << "존재";
				return 0;
			}
		}
	}
	cout << "노존재";
	return 0;
}

