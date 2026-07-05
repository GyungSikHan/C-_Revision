#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n{};

	cin >> n;

	queue<int> qu;
	qu.push(1);

	int idx{};
	int sum{};

	while (!qu.empty() && n >= idx)
	{
		int curr = qu.front();
		qu.pop();
		sum += curr;

		idx++;
		qu.push(curr * 3);
	}

	cout << sum;
}