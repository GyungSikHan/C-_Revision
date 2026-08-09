#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
int n{};
int map[MAX][MAX]{};

int CheckRow()
{
	int cnt1{};
	int cnt2{};
	for (int i = 0; i < n; ++i)
	{
		cnt1 = 0;
		cnt2 = 0;
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] == 1)
				cnt1++;
			else if (map[i][j] == 2)
				cnt2++;
		}

		if (cnt1 == n || cnt2 == n)
			break;
	}

	if (cnt1 == n)
		return 1;
	else if (cnt2 == n)
		return 2;

	return 0;
}

int CheckCol()
{
	int cnt1{};
	int cnt2{};
	for (int i = 0; i < n; ++i)
	{
		cnt1 = 0;
		cnt2 = 0;
		for (int j = 0; j < n; ++j)
		{
			if (map[j][i] == 1)
				cnt1++;
			else if (map[j][i] == 2)
				cnt2++;
		}

		if (cnt1 == n || cnt2 == n)
			break;
	}

	if (cnt1 != n && cnt2 != n)
		return 0;
	if (cnt1 == n)
		return 1;
	return 2;
}

int main()
{
	cin >> n;

	bool bFalg{};
	int checkRow{};
	int checkCol{};
	vector<int>ret{};
	while (bFalg == false)
	{
		checkRow = 0;
		checkCol = 0;

		int y{}, x{}, team{};
		cin >> y >> x >> team;
		map[y][x] = team;

		checkRow = CheckRow();
		if (checkRow != 0)
		{
			bFalg = true;
			break;
		}
		checkCol = CheckCol();
		if (checkCol != 0)
		{
			bFalg = true;
			break;
		}
		ret.push_back(0);
	}

	if (checkRow != 0 || checkCol != 0)
		ret.push_back(checkRow == 0 ? checkCol : checkRow);

	for (const auto& iter : ret)
		cout << iter << " ";
}