#include <iostream>

using namespace std;

int main()
{
	int input{};
	int arr[3][4]{};

	cin >> input;

	for (int i = 0; i< 3; i++)
	{
		for (int j = 2-i; j < 4; ++j)
		{
			arr[i][j] = input++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (arr[i][j] == 0)
				cout << " ";
			else
				cout << arr[i][j];
		}
		cout << endl;
	}
}
