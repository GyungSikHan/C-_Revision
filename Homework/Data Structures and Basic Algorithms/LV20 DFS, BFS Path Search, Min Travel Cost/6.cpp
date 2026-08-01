#include <iostream>
using namespace std;

int Clock[3][3]
{
	{0,12,0},
	{9,0,3},
	{0,6,0}
};

void Print()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (Clock[i][j] != 0)
				cout << Clock[i][j] << " ";
}
void Solution(int count)
{
	while (count != 0)
	{
		int temp[3][3]{};
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				temp[i][j] = Clock[3 - j - 1][i];
			}
		}

		memcpy(Clock, temp, 3 * 3 * sizeof(int));
		count--;
	}

	Print();
}

int main()
{
	int value{};
	cin >> value;

	int data = value % 360;
	switch (data)
	{
	case 90:
		data = 1;
		break;
	case 180:
		data = 2;
		break;
	case 270:
		data = 3;
		break;
	}

	Solution(data);
}