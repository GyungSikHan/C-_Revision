#include <iostream>
using namespace std;

int direct[4][2]
{
	-1,0,
	0,1,
	1,0,
	0,-1
};

int arr[7][7]
{
	0,0,0,0,0,0,0,
	0,0,1,0,1,0,0,
	0,1,-1,0,-1,1,0,
	0,0,1,-1,1,0,0,
	0,0,-1,1,0,1,0,
	0,1,1,0,0,0,0,
	0,0,0,0,0,0,0
};

int Count(int y, int x)
{
	int cnt{};
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + direct[i][0];
		int nx = x + direct[i][1];

		if (ny< 0||ny>=7||nx<0||nx>=7)
			continue;
		if (arr[ny][nx] == 1)
			cnt++;
	}

	if (cnt == 4)
		return 1;
	return 0;
}

int main()
{
	int y{}, x{};
	cin >> y >> x;
	arr[y][x] = 1;

	int ret{};
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (arr[i][j] == -1)
			{
				ret += Count(i, j);
			}
		}
	}
	cout << ret;
}