#include <iostream>
using namespace std;

void Solve(int* nums, int target,int start, int end, int& min, int& max)
{
	if (start > end)
		return;

	int len = (start + end) / 2;
	
	if (nums[len] == target)
	{
		if (min > len)
			min = len;
		if (max < len)
			max = len;
	}
	
	if (nums[len] < target)
	{
		Solve(nums, target,len+1, end, min, max);
	}
	else
	{
		Solve(nums, target,start, len-1, min, max);
	}
}

int main()
{
	int nums[100000]{};
	int size{};
	int target{};

	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		cin >> nums[i];
	}
	cin >> target;
	int min = 987654321;
	int max = -1;
	Solve(nums, target, size,0,size , min, max);

	cout << min << " " << max;
}