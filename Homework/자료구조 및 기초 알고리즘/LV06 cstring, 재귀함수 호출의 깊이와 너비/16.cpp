#include <iostream>
using namespace  std;

void Print(char (*arr)[3])
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void Move(char (*arr)[3], char* dir, int i, int j)
{
	char temp = arr[i][j];
	arr[i][j] = '-';

	if (strcmp(dir, "UP") == 0)
		i--;
	else if (strcmp(dir, "DOWN") == 0)
		i++;
	else if (strcmp(dir, "RIGHT") == 0)
		j++;
	else
		j--;

	arr[i][j] = temp;
}

void Find(char (*arr)[3], char* findChar, char* dir)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == *findChar)
			{
				Move(arr, dir,i,j);
				return;
			}
		}
	}
}

int main()
{
	char arr[5][3]
	{
		'-','-','-',
		'-','-','-',
		'A','T','K',
		'-','-','-',
		'-','-','-'
	};
	for (int i = 0; i < 7; ++i)
	{
		char c{}, dir[256]{};
		cin >> c >> dir;
		Find(arr, &c, dir);
		//Print(arr);
		//cout << endl;
	}

	Print(arr);
}