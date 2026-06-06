#include <iostream>
using namespace std;

int main()
{
	int n{};
	int nums[5000]{};

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	int target{};
	cin >> target;
	int ret = -1;

	for (int i = 0; i < n; ++i)
	{
		if (nums[i] == target)
			ret = i;
	}

	cout << ret;
}