#include <iostream>

using namespace std;

int tree[16]{ 0,15,7,19,0,8,17,25,0,0,0,0,16,18,0,0 };

void DFS(int level, const int data, int& cnt)
{
	if (level == 16)
	{
		cnt = -1;
		return;
	}

	if (tree[level] == 0)
	{
		cnt = -1;
		return;
	}
	if (tree[level] == data)
		return;
	cnt++;
	if (tree[level] < data)
		DFS(level * 2 + 1, data, cnt);
	else
		DFS(level * 2, data, cnt);
}

int main()
{
	int ret{};
	for (int i = 0; i < 5; ++i)
	{
		ret = 1;
		int a{};
		cin >> a;
		DFS(1,a,ret);
		if (ret == -1)
			cout << a << ": 없음" << endl;
		else
			cout << a << ":" << ret << "번만에 찾음" << endl;
	}
}
