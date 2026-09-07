#include <iostream>

using namespace std;

int n{};
int ret{};

void DFS(int cnt, int sum)
{
	if (cnt == n)
	{
		if (sum == 10)
			ret++;
		return;
	}

	for (int i = 1; i < 10; ++i)
		DFS(cnt+1, sum+i);
}

int main()
{
	cin >> n;
	DFS(0,0);

	cout << ret;
}