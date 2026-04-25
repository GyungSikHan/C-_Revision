#include <iostream>
using namespace std;

void SelectSort(char* arr, int idx)
{
	for (int i = 0; i < idx - 1; ++i)
	{
		int minIdx = i;
		for (int j = i + 1; j < idx; ++j)
		{
			if ((int)arr[minIdx] > (int)arr[j])
			{
				minIdx = j;
			}
		}

		char temp = arr[minIdx];
		arr[minIdx] = arr[i];
		arr[i] = temp;
	}
}

void BubbleSort(char* arr, int idx)
{
	for (int i = 0; i < idx-1; ++i)
	{
		for (int j = 0; j < idx-i; ++j)
		{
			if (arr[j-1] > arr[j])
			{
				char temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	char arr[CHAR_MAX]{};
	cin >> arr;

	int idx{};

	while (arr[idx] != '\0')
	{
		idx++;
	}

	//SelectSort(arr, idx);
	BubbleSort(arr, idx);
	cout << arr;
}

