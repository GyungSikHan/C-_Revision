#include <iostream>
#include <vector>

using namespace std;

const int length = 5;
int bst[16]{};

void DFS(const int a, int level)
{
	if (bst[level] == 0)
	{
		bst[level] = a;
		return;
	}

	if (bst[level] < a)
		DFS(a, level * 2 + 1);
	else
		DFS(a, level*2);
}

void Print(int level)
{
	if (bst[level] == 0)
		return;

	Print(level * 2);
	cout << bst[level]<<" ";
	Print(level*2+1);
}

int main()
{
	for (int i = 0; i < length; ++i)
	{
		int a{};
		cin >> a;

		DFS(a, 1);
	}
	Print(1);
}

