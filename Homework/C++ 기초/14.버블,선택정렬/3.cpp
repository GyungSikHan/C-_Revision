#include <iostream>
using namespace std;

int main()
{
	char arr[3][3];
	char input{};
	cin >> input;

	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j < 3-i; ++j)
		{
			arr[i][j] = input++;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if ('A'<=arr[i][j] && arr[i][j] <='Z')
				cout << arr[i][j];
			else
				cout << "";
		}
		cout << endl;
	}
}