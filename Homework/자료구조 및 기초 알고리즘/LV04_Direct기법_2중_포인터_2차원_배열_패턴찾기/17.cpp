#include <iostream>
using namespace std;

int map[3][3]
{
	3,5,1,
	3,8,1,
	1,1,5
};

int Sum(const int (*bitarray)[2], const int& y, const int& x)
{
	int sum{};

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (bitarray[i][j])
			{
				sum += map[y + i][x + j];
			}
		}
	}

	return sum;
}

int main()
{
	int bitarray[2][2]{};
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> bitarray[i][j];
		}
	}

	int max = -1;
	int y{}, x{};
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			int sum = Sum(bitarray, i, j);
			if (max < sum)
			{
				max = sum;
				y = i;
				x = j;
			}
		}
	}

	cout << max << endl;
	cout << "(" << y << "," << x << ")";

}