#include <iostream>

using namespace std;

void run(int input)
{
	int arr[3][3]{};
	int data = 1;
	if (input < 10)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				arr[i][j] = data++;
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 2; j >= 0; --j)
			{
				arr[i][j] = data++;
			}
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int input{};
	cin >> input;

	run(input);
}