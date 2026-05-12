#include <iostream>
using namespace std;

int direct[4][2]
{
	-1,-1,
	-1,1,
	1,-1,
	1,1
};

int map[5][5]
{
	3,3,5,3,1,
	2,2,4,2,6,
	4,9,2,3,4,
	1,1,1,1,1,
	3,3,5,9,2
};
struct Point
{
	int y;
	int x;
};

int Sum(const int& y, const int& x)
{
	int sum = -1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + direct[i][0];
		int nx = x + direct[i][1];

		if (nx<0||nx>=5||ny<0||ny>=5)
			continue;

		sum += map[ny][nx];
	}

	return sum;
}

Point Solve()
{
	int max = -1;
	Point point;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int temp = Sum(i, j);
			if (max < temp)
			{
				max = temp;
				point.y = i;
				point.x = j;
			}
		}
	}

	return point;
}

int main()
{
	Point ret = Solve();

	cout << ret.y << " " << ret.x;
}