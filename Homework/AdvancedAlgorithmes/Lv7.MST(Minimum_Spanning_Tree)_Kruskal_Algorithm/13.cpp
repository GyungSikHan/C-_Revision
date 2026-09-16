#include <iostream>

using namespace std;
const int length = 4;
const int MAX_COUNT = 6;
const int MAX = 987654321;

char puzzle[length][length]{};
int ret = MAX;

void Print()
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			cout << puzzle[i][j];
		}
		cout << endl;
	}
}

bool Check(const char* temp)
{
	cout << "Check str : " << temp << endl;
	return (strcmp(temp, "AAA") == 0);
}


void RotateMatrix(int idx)
{
	char temp[3][3]{};
	int y{}, x{};
	
		int tempY = (idx < 3 ? 1 : 2);
		int tempX = (idx % 2 == 1 ? 1 : 2);

		for (int i = tempY - 1; i <= tempY + 1; ++i)
		{
			for (int j = tempX-1; j <= tempX + 1; ++j)
			{
				temp[y][x] = puzzle[i][j];
				x++;
			}
			x = 0;
			y++;
		}
	

	char temp2[3][3]{};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			temp2[i][j] = temp[3 - j - 1][i];
		}
	}

	y = 0;
	x = 0;
	for (int i = tempY - 1; i <= tempY + 1; ++i)
	{
		for (int j = tempX - 1; j <= tempX + 1; ++j)
		{
			puzzle[i][j] = temp2[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}

void ReverseRotateMatrix(int idx)
{
	char temp[3][3]{};
	int y{}, x{};
	
		int tempY = (idx < 3 ? 1 : 2);
		int tempX = (idx % 2 == 1 ? 1 : 2);

		for (int i = tempY - 1; i <= tempY + 1; ++i)
		{
			for (int j = tempX - 1; j <= tempX + 1; ++j)
			{
				temp[y][x] = puzzle[i][j];
				x++;
			}
			x = 0;
			y++;
		}
	

	char temp2[3][3]{};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			temp2[i][j] = temp[j][3 - i - 1];
		}
	}

	y = 0;
	x = 0;
	for (int i = tempY - 1; i <= tempY + 1; ++i)
	{
		for (int j = tempX - 1; j <= tempX + 1; ++j)
		{
			puzzle[i][j] = temp2[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}

bool Solution(int cnt)
{
	if (cnt != 0)
	{
		cout << "COUNT " << cnt << " PUZZLE" << endl;
		Print();

		for (int i = 0; i < length; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				char temp[4] = { puzzle[i][j] , puzzle[i][j + 1] , puzzle[i][j + 2] };
				if (Check(temp))
					return true;
			}
		}
		cout << endl;
	}
	if (MAX_COUNT <= cnt)
		return false;

	for (int i = 1; i <= 4; ++i)
	{
		RotateMatrix(i);
		if (Solution(cnt + 1))
			return true;
		ReverseRotateMatrix(i);
	}

	return false;
}

int main()
{
	for (int i = 0; i < length; ++i)
		for (int j = 0; j < length; ++j)
			cin >> puzzle[i][j];
	if (Solution(0))
		cout << "가능";
	else
		cout << "불가능";
}