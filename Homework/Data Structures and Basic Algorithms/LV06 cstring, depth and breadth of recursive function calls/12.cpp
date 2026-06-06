#include <iostream>
using namespace std;

void Grabity(int y, int x, char (*str)[3], char c)
{
	if (y + 1 >= 4)
		str[y][x] = c;
	else if (str[y+1][x] == '_')
		Grabity(y + 1, x, str, c);
	else
		str[y][x] = c;
}

int main()
{
	char str[4][3]{};
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> str[i][j];

	for (int i = 3; i >= 0; --i)
	{
		for (int j = 2; j >= 0; --j)
		{
			if (str[i][j] == '_')
				continue;
			Grabity(i, j, str, str[i][j]);
			str[i][j] = '_';
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << str[i][j];
		}
		cout << endl;
	}
}