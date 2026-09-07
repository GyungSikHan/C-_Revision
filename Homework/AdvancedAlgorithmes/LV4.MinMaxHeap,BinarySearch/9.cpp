#include <iostream>
#include <vector>
#include <queue>
#include <string>

std::vector<int> v;
std::priority_queue<int, std::vector<int>, std::greater<>> pq;
int n;

int main()
{
	std::cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> v[i];
		pq.push(v[i]);
	}

	int cnt{};
	while (true)
	{
		int a{};
		bool bFlag{};
		for (int i = 0; i < 2; ++i)
		{
			a = pq.top();
			if (std::find(v.begin(),v.end(), a) == v.end())
			{
				bFlag = true;
				break;
			}
			pq.pop();
			cnt++;
		}
		if (bFlag)
			break;

		pq.push(a*2);
	}

	std::cout << cnt;
}