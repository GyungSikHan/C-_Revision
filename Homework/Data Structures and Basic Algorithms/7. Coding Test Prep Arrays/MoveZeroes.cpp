#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
	    for (int i = 0; i < nums.size(); ++i)
	    {
			if (nums[i] != 0)
				continue;
			int idx = i;

		    for (int j = i+1; j < nums.size(); ++j)
		    {
			    if (nums[j] != 0)
			    {
					swap(nums[idx], nums[j]);
			    	idx = j;
			    }
		    }
	    }
    }
};

int main()
{
    vector<int>v{ 0,1,0,3,12 };
    Solution solution;
    solution.moveZeroes(v);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
}