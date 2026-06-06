#include <iostream>
using namespace std;

int main()
{
	int arr[3][3]{};
	char c{};
	int data = 6;

	cin >> c;

	if ('0' <= c && c <= '9')
	{
		for (int i = 0; i< 3; i++)
		{
			for (int j = i; j<3; j++)
			{
				arr[i][j] = data--;
			}
		}
	}
	else if ('A' <= c && c <= 'Z')
	{
		int idx = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < idx; j++)
			{
				arr[i][j] = data--;
			}
			idx++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == 0)
				cout << " ";
			else
				cout << arr[i][j];
		}
		cout << endl;
	}
}