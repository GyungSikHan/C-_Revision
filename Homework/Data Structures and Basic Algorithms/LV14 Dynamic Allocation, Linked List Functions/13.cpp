#include <iostream>
using namespace std;

void Sort(int* arr, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int idx = i;
		int key = arr[i];
		for (int j = i; j >= 0; --j)
		{
			if (arr[j-1] > key)
			{
				arr[j] = arr[j-1];
				idx = j-1;
			}
			else
				break;
		}
		arr[idx] = key;
	}
}
int main()
{
	int number[6]{};
	char command[7]{};

	for (int i = 0; i < 6; ++i)
		cin >> number[i];
	cin >> command;

	Sort(number, 6);
	int count = 5;

	for (int i = 0; i < strlen(command); ++i)
	{
		if (command[i] == 'm')
		{
			cout << number[0]<<" ";
			number[0] = 987654321;
			count--;
		}
		else
		{
			cout << number[count]<<" ";
			number[count] = 987654321;
			count--;
		}
		Sort(number,6);
	}
}