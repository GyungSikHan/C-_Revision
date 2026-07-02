#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        int one = 1;
	    for (int i = digits.size()-1; i >= 0; --i)
	    {
            digits[i] += one;
            one = 0;
            if (digits[i] > 9)
            {
                digits[i] %= 10;
                one = 1;
            }
            else
                break;
	    }

        if (one == 1)
        {
            std::vector<int> ret(digits.size()+1,0);
            ret[0] = 1;
            memcpy(ret.data()+1, digits.data(), sizeof(int) * digits.size());
            digits.resize(ret.size(), 0);
        	memcpy(digits.data(), ret.data(), sizeof(int) * ret.size());
        }
        return digits;
    }
};

int main()
{
    std::vector<int> v{1,2,3};
    //std::vector<int> v{4,3,2,1};
    //std::vector<int> v{9};

    Solution solution;
    std::vector<int>ret = solution.plusOne(v);

    for (int i = 0; i < ret.size(); ++i)
        std::cout << ret[i];
    
}