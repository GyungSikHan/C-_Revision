#include <iostream>
using namespace std;

void Solve(int (*arr)[3], int y, int x, const int a, const int b)
{
	if (y == 4)
		return;

	if (arr[y][x] >= a && arr[y][x] <= b)
		arr[y][x] = -1;

	x++;
	if (x == 3)
	{
		x = 0;
		y++;
	}

	Solve(arr, y, x, a, b);
}

void Print(int (*arr)[3])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == -1)
				cout << "# ";
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int arr[4][3]
	{
		1,5,3,
		4,5,5,
		3,3,5,
		4,6,2
	};
	int a{}, b{};
	cin >> a >> b;

	Solve(arr, 0, 0, a, b);
	Print(arr);
}