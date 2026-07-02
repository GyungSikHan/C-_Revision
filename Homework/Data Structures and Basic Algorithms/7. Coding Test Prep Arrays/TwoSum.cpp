#include <iostream>
#include <vector>

std::pair<int, int> TwoSum(std::vector<int>& nums, int target)
{
	bool bFlag{};
	std::pair<int, int> ret;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i+1; j < nums.size(); ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				ret.first = i;
				ret.second = j;
				bFlag = true;
				break;
			}
		}
		if (bFlag)
			break;
	}
	return ret; // Return an invalid pair if no solution is found
}

int main()
{
	//std::vector<int> nums = { 2, 7, 11, 15 };
	std::vector<int> nums = { 3,2,4};
	//int target = 9;
	int target = 6;

	auto result = TwoSum(nums, target);

	std::cout << result.first << " " << result.second;
	return 0;
}