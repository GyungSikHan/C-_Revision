#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[2][5]
{
	{-1,0,0,0,1},
	{-1,0,-1,1,1 }
};
int dx[2][5]
{
	{0,0,-1,1,0},
	{-1,0,1,1,-1}
};

char arr[5]{};
int n{}, k{};
int y{}, x{}, types{};
vector<vector<char>> map;

void Solution()
{
	for (int i = 0; i < 5; ++i)
	{
		int ny = dy[types - 1][i] + y;
		int nx = dx[types - 1][i] + x;

		arr[i] = map[ny][nx];
	}
}

int main()
{
	cin >> n >> k;
	map.assign(n, vector<char>(n, '\0'));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];

	for (int i = 0; i < k; ++i)
	{
		memset(arr, '\0', sizeof(arr));
		cin >> y >> x >> types;
		Solution();

		cout << arr;
	}
}