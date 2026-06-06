#include <iostream>

using namespace std;

int main()
{
	int arr[3][4]{};
	int num = 1;

	for (int i = 2; i>= 0; i--)
	{
		for (int j = 3; j >= 0; j--)
		{
			arr[i][j] = num++;
		}
	}

	int input{};
	cin >> input;

	for (int i = 0; i < 3; i++)
	{
		arr[i][input] = 0;
	}

	for (int i = 0; i<3;i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}