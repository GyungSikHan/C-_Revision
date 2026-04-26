#include <iostream>

using namespace  std;

int main()
{
	int arr[5][5]
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	};
	int input{};

	cin >> input;

	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 4)
		{
			for (int j = 0; j < 5; j++)
			{
				arr[i][j] = input;
			}
		}
		else
		{
			arr[i][0] = input;
			arr[i][4] = input;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == 0)
				cout << "_";
			else
				cout << arr[i][j];
		}
		cout << endl;
	}
}