#include <iostream>
using namespace std;

const int MAX = 5;
int arr[MAX]{};
int ret[MAX]{};
int CNT{};
void Print(int cnt)
{
	for (int i = 0; i < cnt; ++i)
	{
		cout << ret[i];
		if (i + 1 != cnt)
			cout << "+";
	}
	cout << endl;
}

void DFS(int level, int sum, int idx)
{
	if (sum > 20)
		return;
	if (level == MAX)
	{
		if (10<=sum && sum<=20)
		{
			CNT++;
			Print(idx);
		}
		return;
	}

	ret[idx] = arr[level];
	DFS(level + 1, sum + arr[level], idx + 1);
	ret[idx] = -1;
	DFS(level + 1, sum, idx);
}
int main()
{
	for (int i = 0; i < MAX; ++i)
		cin >> arr[i];

	DFS(0,0,0);

	cout << CNT;
}