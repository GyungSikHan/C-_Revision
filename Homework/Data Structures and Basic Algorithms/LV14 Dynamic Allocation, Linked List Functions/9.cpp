#include <iostream>
using namespace std;

void InputData(char* arr, int len)
{
	for (int i = 0; i < len; ++i)
	cin >> arr[i];
}

int Count(char (*arr)[4], int len, int j)
{
	int count{};
	for (int i = 0; i < len; ++i)
	{
		if (arr[i][j] != '#')
			count++;
	}

	return count;
}

int main()
{
	char arr[4][4]{};
	for (int i = 0; i < 4; ++i)
		InputData(arr[i], 4);

	for (int i = 0; i < 4; ++i)
	{
		cout << Count(arr, 4, i) << " ";
	}
}