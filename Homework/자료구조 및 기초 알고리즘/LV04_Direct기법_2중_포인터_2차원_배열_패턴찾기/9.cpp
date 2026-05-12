#include <iostream>
using namespace std;

int Sum(const int (*image)[4], const int& y, const int& x)
{
	if (y + 2 > 4 || x + 3 > 4)
		return -1;

	int sum{};
	for (int i = y; i < y+2; ++i)
	{
		for (int j = x; j < x+3; ++j)
		{
			sum += image[i][j];
		}
	}

	return sum;
}

int main()
{
	int image[4][4]{};

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> image[i][j];
		}
	}

	struct Point
	{
		int y;
		int x;
	};

	Point point{-1,-1};

	int max{};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int temp = Sum(image, i, j);
			if (max< temp )
			{
				max = temp;
				point.y = i;
				point.x = j;
			}
		}
	}

	cout << "(" << point.y << "," << point.x << ")" << endl;
}