#include <iostream>
using namespace std;

int arr[3][3]
{
	-1,5,4,
	3,-1,-1,
	-1,-1,1
};

void Rotate()
{
	int temp[3][3]{};
	memcpy(temp, arr, sizeof(temp));

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int y = i;
			int x = j;
			if (i == 0)
			{
				x += (2*(j+1));
				while (x>=3)
				{
					y++;
					x -= 3;
				}
			}
			else if (i == 1)
			{
				if (j == 0)
				{
					x -= 2;// *(j + 1));
					while (x<0)
					{
						y--;
						x = 3 + x;
					}
				}
				else if (j == 2)
				{
					x += 2;//(2 * (j + 1));
					while (x>=3)
					{
						y++;
						x -= 3;
					}
				}
			}
			else
			{
				x -= (2 * (3-j));
				while (x<0)
				{
					y--;
					x = 3 + x;
				}
			}
			arr[y][x] = temp[i][j];
		}
	}
}

int main()
{
	int n{};
	cin >> n;
	for (int i = 0; i < n; ++i)
		Rotate();
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == -1)
				cout << "_";
			else
				cout << arr[i][j];
		}
		cout << endl;
	}
}