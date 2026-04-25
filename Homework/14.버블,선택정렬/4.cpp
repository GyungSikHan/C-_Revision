#include <iostream>
using namespace std;

int main()
{
	int arr[6]{};
	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 5; ++i)
	{
		int maxIdx = i;
		for (int j = i+1; j < 6; ++j)
		{
			if (arr[maxIdx] < arr[j])
			{
				maxIdx = j;
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << arr[i];
	}

}