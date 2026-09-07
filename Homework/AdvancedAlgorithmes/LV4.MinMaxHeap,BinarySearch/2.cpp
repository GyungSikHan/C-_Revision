#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;

int n{};
string strArr[MAX]{};
int m{};

int Comparison(const string& a, const string& b)
{
	int bingSize = std::min(a.size(), b.size());

	for (int i = 0; i < bingSize; ++i)
	{
		if (a[i] < b[i])
			return 0;
		else if (a[i] > b[i])
			return 1;
	}

	if (a.size() < b.size())
		return 0;
	return 1;
}

bool BinarySearch(const string& search, int time)
{
	if (time == 0)
		return false;

	int start{}, end = n;
	while (start<=end && time > 0)
	{
		int mid = (start + end) / 2;

		if (search == strArr[mid])
			return true;
		switch (int temp = Comparison(strArr[mid], search))
		{
		case 0:
			start = mid + 1;
			break;
		case 1:
			end = mid - 1;
			break;
		}
		time--;
	}

	return false;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> strArr[i];
	cin >> m;

	sort(strArr, strArr + n);

	for (int i = 0; i < m; ++i)
	{
		string str{};
		int time{};

		cin >> str >> time;
		cout << (BinarySearch(str, time) ? "pass" : "fail") << endl;
	}
}