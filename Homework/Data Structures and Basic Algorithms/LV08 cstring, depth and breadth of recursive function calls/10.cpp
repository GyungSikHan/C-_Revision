#include <iostream>
using namespace std;

void Sum(int (*arr)[4], int* ret, int sum, int i, int j)
{
	if (i == 3)
	{
		ret[j] = sum;
		return;
	}

	Sum(arr, ret, sum + arr[i][j], i + 1, j);
}

int main()
{
	int arr[3][4]
	{
		3,4,1,5,
		3,4,1,3,
		5,2,3,6
	};
	int sum[4]{};
	for (int i = 0; i < 4; ++i)
	{
		Sum(arr, sum, 0, 0, i);
	}

	int idx{};
	cin >> idx;

	cout << sum[idx];
}