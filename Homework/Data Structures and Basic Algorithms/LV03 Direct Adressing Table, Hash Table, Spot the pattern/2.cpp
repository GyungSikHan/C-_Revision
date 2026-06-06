#include <iostream>
using namespace std;

int main()
{
	int arr[3][4]
	{
		65000,35,42,70,
		70,35,65000,1300,
		65000,30000,38,42
	};

	int ret[65536]{};

	for (int i = 0; i < 12; ++i)
	{
		ret[arr[i / 4][i % 4]]++;
	}

	int max = ret[0];
	int idx{};
	for (int i = 1; i < 65536; ++i)
	{
		if (max<ret[i])
		{
			max = ret[i];
			idx = i;
		}
	}

	cout << idx;
}