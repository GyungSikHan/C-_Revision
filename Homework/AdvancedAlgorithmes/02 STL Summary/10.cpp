#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n{};
vector<vector<int>> v;
vector<vector<int>> bit;
int arr[11]{};

void InputMap()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
}

void InputBit()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> bit[i][j];
}

int CheckMask(const vector<int>& map, const vector<int>& bitmap)
{
	int i{};
	for (i ; i < map.size(); ++i)
		if (bitmap[i] == 1)
			break;
	
	return map[i];
}

void Sort(vector<int>& temp)
{
	sort(temp.begin(), temp.end(), [](const int& a, const int& b)
		{
			if (arr[a] == arr[b])
				return a < b;

			return arr[a] > arr[b];
		});
}

vector<int> Count()
{
	for (int i = 0; i < n; ++i)
	{
		int idx = CheckMask(v[i], bit[i]);
		arr[idx]++;
	}

	int idx{};
	vector<int> temp(n, 0);
	for (int i = 1; i < 11; ++i)
	{
		if (arr[i] != 0)
		{
			for (int j = 0; j< arr[i]; j++)
				temp[idx++] = i;
		}
	}

	Sort(temp);
	return temp;
}

int main()
{
	cin >> n;
	v.assign(n, vector<int>(n, 0));
	bit.assign(n, vector<int>(n, 0));

	InputMap();
	InputBit();
	for (const auto& iter : Count())
		cout << iter << " ";
}