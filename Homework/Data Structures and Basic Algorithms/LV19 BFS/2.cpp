#include <iostream>
#include <queue>
using namespace std;

char arr[10]{};
int map[8][8]{};

void DFS(string& ret, int idx)
{
	if (idx == 8)
		return;
	

	for (int i = 0; i < 8; ++i)
	{
		if (map[idx][i] == 1)
		{
			ret += arr[i];
			DFS(ret, i);
		}
	}
}

int main()
{
	cin >> arr;
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			cin >> map[i][j];
	
	string ret{};
	ret += arr[0];
	DFS(ret, 0);
	cout << ret;
}