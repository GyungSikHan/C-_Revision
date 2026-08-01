#include <iostream>
using namespace std;

char arr[4]{};
int cnt{};

char ret[4]{};

void Print()
{
	for (int i = 0; i < cnt; ++i)
		cout << ret[i];
	cout << endl;
}

void DFS(int level)
{
	if (level == cnt)
	{
		Print();
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		ret[level] += arr[i];
		DFS(level + 1);
		ret[level] = '\0';
	}
}

int main()
{
	for (int i = 0; i < 4; ++i)
		cin >> arr[i];
	cin >> cnt;

	DFS(0);
}