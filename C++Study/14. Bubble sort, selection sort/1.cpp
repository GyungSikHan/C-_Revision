//bubble sort
#include <iostream>
using namespace std;

int main()
{
	int arr[6]{7,3,2,5,6,1 };

	for (int i = 0; i < 6; ++i)
	{
		bool bFlag{};
		for (int j = 0; j < 5-i; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				bFlag = true;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (!bFlag)
			break;
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << arr[i] << " ";
	}
}