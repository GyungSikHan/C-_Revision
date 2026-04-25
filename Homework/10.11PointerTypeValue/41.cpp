#include <iostream>
using namespace std;

int main()
{
	int arr[3][3]
	{
		3,1,6,
		7,8,4,
		9,2,3
	};
	int a{}, b{}, c{};
	cin >> a >> b >> c;

	arr[a][b] = c;

	int min = INT_MAX, max = INT_MIN;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] < min)
				min = arr[i][j];
			if (max < arr[i][j])
				max = arr[i][j];
		}	
	}

	cout << min + max;
}