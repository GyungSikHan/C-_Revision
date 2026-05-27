#include <iostream>
using namespace std;

int main()
{
	int nums[100001]{};
	int n{};
    int k{};
    int temp = -10001;
    int idx{};
    cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        cin>>nums[i];
        if(temp < nums[i])
        {
            temp = nums[i];
            idx = i;
        }
    }
    cin>>k;
    nums[idx] = -10001;
    while (k != 1)
    {
        int temp2 = -10001;
        int idx2{};
        for (size_t i = 0; i < n; i++)
        {
            if(temp >= nums[i] && temp2 <= nums[i])
            {
                temp2 = nums[i];
                idx2 = i;
            }
        }
        k--;
        temp = temp2;
        nums[idx2] = -10001;
    }
    
	cout<<temp;
}