#include <algorithm>
#include <iostream>
using namespace std;

int arr[6]{ 1,5,4,2,-5,-7 };
int n{};

void Sort(int* array, int length)
{
	for (int i = 1; i < 6; ++i)
	{
		int temp = arr[i];
		int key = i;
		for (int j = i-1; j >= 0; --j)
		{
			if (temp > arr[j])
			{
				arr[key] = arr[j];
				key = j;
			}
			else
				break;
		}
		arr[key] = temp;
	}
}

int main()
{
	Sort(arr,6);
	cin >> n;
	cout << arr[n-1];
}