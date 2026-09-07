#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> Maximum(vector<int>& v)
{
	int mi = 987654321;
	int mx = -987654321;
	for (const auto& iter : v)
	{
		if (iter == 0 )
			continue;
		mi = min(mi, iter);
		mx = max(mx, iter);
	}

	return make_pair(mi,mx);
}

int main()
{
	int n{};
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	vector<pair<int, int>>ret;
	for (auto& iter : v)
	{
		ret.push_back(Maximum(iter));
	}

	int MAX = 1;
	int MIN = 1;
	for (const auto& iter: ret)
	{
		int a = MAX * iter.first;
		int b = MAX * iter.second;
		int c = MIN * iter.first;
		int d = MIN * iter.second;

		MAX = max({ a, b, c, d });
		MIN = min({ a, b, c, d });
	}

	cout << MAX;
}