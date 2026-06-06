#include <iostream>

using namespace std;

int main()
{
	int arr[7]{};
	
	for (int i = 0; i< 7; i++)
	{
		cin >> arr[i];
	}

	int min=INT_MAX, max = INT_MIN;
	for (int i = 0; i< 7; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	cout << "MAX=" << max << endl;
	cout << "MIN=" << min << endl;
}