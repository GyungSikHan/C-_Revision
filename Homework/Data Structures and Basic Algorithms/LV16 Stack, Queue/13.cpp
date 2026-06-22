#include <iostream>

#include "queue.h"
#include "vector.h"
using namespace std;
#define NO 987654321
struct Point
{
public:
	Point():y(),x(){}
	Point(int y, int x):y(y),x(x){}
	int y{};
	int x{};
};

int A[3][3]
{
	2,6,3,
	7,1,1,
	3,4,2
};
int B[2][4]
{
	6,4,2,4,
	1,1,5,8
};
int C[2][3]
{
	9,2,3,
	4,2,1
};

int map[3][3]{};

void UpdateMap(int jung, Homework::vector<int>* Max = nullptr,
	Homework::vector<int>* Min = nullptr)
{
	switch (jung)
	{
	case 0:
		for (int i = 0; i < 3; ++i)
			map[jung][i] = (*Max)[i];
		break;
	case 1:
		for (int i = 0; i < 3; ++i)
			map[jung][i] = (*Min)[i];
		break;
	case 2:
		for (int i = 0; i < 2; ++i)
			map[jung][i] = (*Min)[i];
		map[jung][2] = (*Max)[0];
		break;
	}
}

void Solution(int jung)
{
	Homework::vector<int> Max((jung == 0 ? 3 : 1), -1);
	Homework::vector<int> Min((jung == 1 ? 3 : 2), 999);
	int ty{}, tx{};
	switch (jung)
	{
	case 0:
		for (size_t i = 0; i < 3; ++i)
		{
			ty = 0;
			tx = 0;
			for (int y = 0; y < 3; ++y)
			{
				for (int x = 0; x < 3; ++x)
				{
					if (A[y][x] == NO)
						continue;
					if (Max[i] < A[y][x])
					{
						Max[i] = A[y][x];
						ty = y;
						tx = x;
					}
				}
			}
			A[ty][tx] = NO;
		}
		UpdateMap(jung, &Max);
		break;
	case 1:
		for (size_t i = 0; i < 3; ++i)
		{
			ty = 0;
			tx = 0;
			for (int y = 0; y < 2; ++y)
			{
				for (int x = 0; x < 4; ++x)
				{
					if (B[y][x] == NO)
						continue;
					if (Min[i] > B[y][x])
					{
						Min[i] = B[y][x];
						ty = y;
						tx = x;
					}
				}
			}
			B[ty][tx] = NO;
		}
		UpdateMap(jung, nullptr, &Min);
		break;
	case 2:
		for (size_t i = 0; i < 2; ++i)
		{
			ty = 0;
			tx = 0;
			for (int y = 0; y < 2; ++y)
			{
				for (int x = 0; x < 3; ++x)
				{
					if (C[y][x] == NO)
						continue;
					if (Min[i] > C[y][x])
					{
						Min[i] = C[y][x];
						ty = y;
						tx = x;
					}
				}
			}
			C[ty][tx] = NO;
		}

		for (int y = 0; y < 2; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				if (C[y][x] == NO)
					continue;
				if (Max[0] < C[y][x])
				{
					Max[0] =  C[y][x];
					C[y][x] = NO;
				}
			}
		}
		UpdateMap(jung, &Max, &Min);
		break;
	}
}

int main()
{
	for (int i = 0; i < 3; ++i)
		Solution(i);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}