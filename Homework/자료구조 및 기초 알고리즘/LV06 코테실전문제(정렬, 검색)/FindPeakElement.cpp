#include <iostream>
using namespace std;

int main()
{
	int nums[1001]{};
	int n{};
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	int idx;
	for (int i = 1; i < n-1; ++i)
	{
		if (nums[i-1] < nums[i] && nums[i] > nums[i+1] )
		{
			idx = i;
		}
	}

	cout <<"output: " << idx << " Explanation" << nums[idx];
}