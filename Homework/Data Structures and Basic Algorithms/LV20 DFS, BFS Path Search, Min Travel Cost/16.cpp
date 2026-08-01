#include <iostream>
using namespace std;

const int MAX = 3;
int arr[2][MAX][MAX]{};

bool Check()
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			if (arr[0][i][j] != arr[1][i][j])
				return false;

	return true;
}

int main()
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < MAX; ++j)
			for (int k = 0; k < MAX; ++k)
				cin >> arr[i][j][k];
	int cnt{};

	while (Check() == false)
	{
		int temp[MAX][MAX]{};
		memcpy(temp, arr[0], sizeof(int) * MAX * MAX);
		for (int i = 0; i < MAX; ++i)
		{
			for (int j = 0; j < MAX; j++)
			{
				arr[0][i][j] = temp[j][MAX-1-i];
			}
		}
		cnt++;
	}

	cout << cnt << endl;
}