#include <iostream>
using namespace std;

int main()
{
	int arr[4]{};
	for (int i = 0; i < 4; ++i)
	{
		cin >> arr[i];
	}

	int map[4][4]{};
	for (int i = 0; i < 16; ++i)
	{
		map[i / 4][i % 4] = i + 1;
	}

	int ret[4][4]{};

	int data = 1;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			if (arr[i] == map[j / 4][j % 4])
				ret[j / 4][j % 4] = data++;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << ret[i][j]<<" ";
		}
		cout << endl;
	}
}