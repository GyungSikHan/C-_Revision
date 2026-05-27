#include <iostream>
using namespace std;
//o
struct point
{
	int s{}, e{};
};

int main()
{
	int n{};
	int nums[100001]{};
	int target{};

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	cin >> target;

    if(n == 0)
    {
        cout<<-1<<","<< -1;
        return 0;
    }

    int ret[10001]{-1,};
    int idx{};
    for (size_t i = 0; i < n; i++)
    {
        if(target == nums[i])
        {
            ret[idx] = i;
            idx++;
        }
    }

    cout<<ret[0]<<","<<ret[idx-1];
    
}