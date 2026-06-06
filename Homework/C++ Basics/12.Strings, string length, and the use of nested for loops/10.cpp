#include <iostream>

using namespace std;

int main()
{
	char arr[5][5]
	{
		'0','0','0','0','0',
		'0','0','0','0','0',
		'0','0','0','0','0',
		'0','0','0','0','0',
		'0','0','0','0','0'
	};
	int input{};
	char cinput{};

	cin >> input >> cinput;

	for (int i = 4; i >= 0; i--)
	{
		arr[input - 1][i] = cinput++;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}