#include <iostream>

using namespace std;

int main()
{
	int size = 6;
	int arr[6]{ 5,3,8,1,2,7 };

	for (int i = 0; i < size - 1; ++i)
	{
		bool bFlag{};
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				bFlag = true;
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