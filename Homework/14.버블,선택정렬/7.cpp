#include <iostream>
using namespace std;

void Magic(int (*arr)[3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			cin >> arr[i][j];
		}
	}
}

void Output(int (*arr)[3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == 0)
				cout << " ";
			else
				cout << arr[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int arr[3][3]{};
	Magic(arr);
	Output(arr);
}