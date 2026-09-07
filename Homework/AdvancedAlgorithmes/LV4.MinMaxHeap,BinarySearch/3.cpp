#include <iostream>
#include <vector>
using namespace std;

pair<int, int > point;
int n{};
vector<vector<char>> v;

int main()
{
	cin >> n;
	v.assign(n, vector<char>(n, '0'));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];


	int start = 0, end = n * n;
	int answer = -1;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int y = mid / n;
		int x = mid % n;
		if (v[y][x] == '#')
		{
			answer = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	

	cout << answer / n << " " << answer % n;
}