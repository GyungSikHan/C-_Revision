#include <iostream>

using namespace std;

int tree[16]{0,3,2,5,1,6,0,7,0,0,0,0,0,0,4,8};

void DFS(int level)
{
	if (level >= 16)
		return;
	if (tree[level] == 0)
		return;

	DFS(level * 2);
	DFS(level * 2+1);
	cout << tree[level];
}

int main()
{
	DFS(1);
}