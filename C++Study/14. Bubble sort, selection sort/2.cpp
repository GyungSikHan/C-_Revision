//Selection Sort
#include <iostream>
using namespace std;

int main()
{
	int arr[6]{ 7,3,2,5,6,1 };

	for (int i = 0; i < 5; ++i)
	{
		int minIdx = i;
		for (int j = i + 1; j < 6; ++j)
		{
			if (arr[minIdx] > arr[j])
			{
				minIdx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;

	}

	for (int i = 0; i < 6; ++i)
	{
		cout << arr[i] << " ";
	}
}