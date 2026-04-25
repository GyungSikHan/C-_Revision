#include <iostream>

using namespace std;

int main()
{
	int arr[6]{ 5,1,9,7,2,3 };

	for (int j = 0; j < 6; j++)
	{
		for (int i = 1; i < 6; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				int temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
			}
		}
	}
}