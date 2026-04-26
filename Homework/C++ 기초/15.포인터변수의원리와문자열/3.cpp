#include <iostream>
using namespace std;

void SelectSort(char* arr, int length)
{
	for (int i = 0; i < length-1; ++i)
	{
		for (int j = 0; j < length-i; ++j)
		{
			if (arr[j] == '\0')
				break;

			if (arr[j - 1] > arr[j])
			{
				char temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void AddArray(char (*arr)[6], char* ret)
{
	int idx{};
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (arr[i][j] == '\0')
				break;
			ret[idx++] = arr[i][j];
		}
	}
}
int main()
{
	char arr[2][6]{};
	for (int i = 0; i < 2; ++i)
	{
		cin >> arr[i];
	}
	SelectSort(arr[0], 6);
	SelectSort(arr[1], 6);
	char ret[CHAR_MAX]{};

	AddArray(arr, ret);
	cout << ret;
}