#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


class Solution
{
	vector<int> original;
	int n;
public:

	Solution(const vector<int>& nums)
	{
		original = nums;
		n = static_cast<int>(original.size());
	}

	vector<int> reset()
	{
		return original;
	}

	vector<int> shuffle()
	{
		//make a copy of the original
		vector<int> shuffled = original;
		std::srand(time(NULL));

		vector<bool> visited(n, 0);
		int idx{};

		while (idx != n)
		{
			int r = rand() % 3;
			if (visited[r] == 1)
				continue;
			shuffled[r] = original[idx];
			idx++;
			visited[r] = 1;
		}

		return shuffled;
	}
};

void Print(vector<int> v)
{
	for (const auto& s : v)
		cout << s << " ";
	cout << endl;
}

int main()
{
	vector<int> shuffle{ 1,2,3 };
	Solution solution(shuffle);
	
	Print(solution.shuffle());
	Print(solution.reset());
	Print(solution.shuffle());


}