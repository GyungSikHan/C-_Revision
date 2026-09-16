#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; ++j)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
	if (low >= high)
		return;

	int p = partition(arr,low,high);
	quickSort(arr,low,p-1);
	quickSort(arr, p + 1, high);
}

int main()
{
	vector<int> arr{ 4,2,7,1,3,6,8 };
	quickSort(arr, 0, arr.size() - 1);

	for (const int& iter : arr)
	{
		cout << iter << " ";
	}
}