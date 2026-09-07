#include <iostream>

using namespace std;

char tree[256]{ 0,'A','B','C','D','E',0,'G' };
int n = 7;

void dfs(int level, int nowIdx)
{
	int left = nowIdx * 2;
	int right = nowIdx * 2 + 1;


	if (left <= n && tree[left] != 0)
		dfs(level + 1, left);

	cout << tree[nowIdx] << " ";

	if (right <= n && tree[right] != 0)
		dfs(level + 1, right);
}


int main()
{
	dfs(1, 0);
}