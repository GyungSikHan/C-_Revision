//insertion sort
#include <iostream>
using namespace std;

int main()
{
	int arr[6]{ 7,3,2,5,6,1 };

	for (int i = 1; i < 6; ++i)
	{
		int data = arr[i];
		int idx = i;
		for (int j = i-1; j >= 0; --j)
		{
			if (data < arr[j])
			{
				arr[idx] = arr[j];
				idx = j;
			}
			else
				break;
		}
		arr[idx] = data;
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << arr[i] << " ";
	}
}
