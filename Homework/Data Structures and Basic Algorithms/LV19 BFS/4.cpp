#include <iostream>
using namespace std;

int arr[8]{};

void DFS(int& sum, int idx, int level)
{
	if (level == 2)
	{
		sum += arr[idx];
		return;
	}

	DFS(sum, idx * 2, level + 1);
	DFS(sum, idx * 2 + 1, level + 1);
}

int main()
{
	for (int i = 1; i < 8; ++i)
		cin >> arr[i];

	int sum{};
	DFS(sum, 1, 0);
	cout << sum;
}