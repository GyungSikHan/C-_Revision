#include <iostream>
using namespace std;

int main()
{
	int arr[3][5]
	{
		1,3,3,5,1,
		3,6,2,4,2,
		1,9,2,6,5
	};

	int n{};
	cin >> n;

	int ret[11]{};
	for (int i = 0; i < 15; ++i)
	{
		ret[arr[i / 5][i % 5]]++;
	}

	for (int i = 1; i < 11; ++i)
	{
		if (ret[i] == n)
			cout << i << " ";
	}
}