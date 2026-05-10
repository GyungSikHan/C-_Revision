#include <iostream>
using namespace std;

int main()
{
	int arr[3][3]{};
	for (int i = 0; i < 9; ++i)
	{
		cin >> arr[i / 3][i % 3];
	}

	int ret[10]{};
	for (int i = 0; i < 9; ++i)
	{
		ret[arr[i / 3][i % 3]]++;
	}

	for (int i = 1; i < 10; ++i)
	{
		if (!ret[i])
			cout << i << " ";
	}
}