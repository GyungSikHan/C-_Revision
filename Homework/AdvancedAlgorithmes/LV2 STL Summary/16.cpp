#include <iostream>
#include <vector>

using namespace std;

int n{}, k{};
vector<vector<int>> map{};

void FillMap()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
}

void Rotate()
{
	vector<vector<int>> temp = map;
	for (int i = 0; i < n; ++i)
	{
		for (int j = n-1; j >= 0; --j)
		{
			map[i][n - j - 1] = temp[j][i];
		}
	}
}

void Print()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cin >> n >> k;
	map.assign(n, vector<int>(n, 0));

	FillMap();
	for (int i = 0; i < k; ++i)
	{
		Rotate();
		Print();
	}
}