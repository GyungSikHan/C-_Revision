#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n{}, m{};
vector<int> v{};

int main()
{
	cin >> n >> m;

	priority_queue<int, vector<int>> big{};
	priority_queue<int, vector<int>, std::greater<>> small{};

	for (int i = 0; i < n; ++i)
	{
		int a{};
		cin >> a;

		big.push(a);
		small.push(a);
	}

	int ret = 1;
	for (int i = 0; i < m; ++i)
	{
		if (i == 0)
			ret *= small.top();
		else
		{
			ret *= big.top();
			big.pop();
		}
	}

	cout << ret;
}