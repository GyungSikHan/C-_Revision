#include <iostream>
#include <map>

using namespace std;

char datas[10] = "ABCDEG";
char datas2[10]{ 0,'A','B','C','D','E','G',0 };
int tree[6][6]
{
	{0,1,1,0,0,0},
	{0,0,0,1,1,0},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
};

void dfs(int level, int now)
{
	cout << datas[now];
	for (int i = 0; i < 6; ++i)
	{
		if (tree[now][i] == 1)
			dfs(level + 1, i);
	}
}
void dfs2(int level, int nowIdx)
{
	cout << datas2[nowIdx];
	int left = nowIdx * 2;
	if (left < 8 && datas2[left] != 0)
		dfs2(level + 1, left);
	int right = nowIdx * 2 + 1;
	if (right < 8 && datas2[right] != 0)
		dfs2(level + 1, right);
}

int main()
{
	dfs(0,0);
	cout << endl;
	dfs2(0,1);
	cout << endl;
}