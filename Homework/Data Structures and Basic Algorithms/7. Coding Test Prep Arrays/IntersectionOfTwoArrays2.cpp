#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

vector<int> singleNumber(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> result;
	
	for (int i = 0; i < nums1.size(); ++i)
	{
		for (int j = 0; j < nums2.size(); ++j)
		{
			if (nums1[i] == nums2[j])
			{
				result.push_back(nums1[i]);
				nums1[i] = INF;
				nums2[j] = INF;
				break;
			}
		}	
	}
	return result;
}

int main()
{
	std::vector<int> nums1 = /*{ 1,2,2,1 }*/{4,9,5};
	std::vector<int> nums2 = /*{ 2,2 }*/ {9,4,9,8,4};

	vector<int> result = singleNumber(nums1, nums2);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
	return 0;
}