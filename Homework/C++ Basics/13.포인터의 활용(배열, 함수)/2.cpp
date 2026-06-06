#include <iostream>
using namespace std;

void Find(char (*arr)[3], char c, int* y, int* x)
{
	bool bFlag{};

	for (int i = 0; i< 3; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == c)
			{
				bFlag = true;
				*y = i;
				*x = j;
				break;
			}
		}
	}

	if (!bFlag)
	{
		*y = -1;
		*x = -1;
	}
}

int main()
{
	char arr[3][3]
	{
		'A','D','F',
		'Q','W','E',
		'Z','X','C'
	};

	char c{};
	cin >> c;

	int y{}, x{};
	Find(arr, c, &y, &x);

	if (y == -1 || x == -1)
		cout << "없음" << endl;
	else
		cout << y << "," << x << endl;
}