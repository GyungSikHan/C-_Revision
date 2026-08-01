#include <iostream>
#include <queue>
using namespace std;

const int MAX = 10;
int cnt{};
string key[MAX];
char arr[4]{};

bool Check(int idx)
{
	for (int i = 0; i < 4; ++i)
	{
		if (key[idx][i] != arr[i])
			return false;
	}

	return true;
}

int s(int idx, int ret)
{
	for (int i = 0; i < 4; ++i)
	{
		if (key[idx][i] != arr[i])
		{
			int temp = key[idx][i] - arr[i];
			if (i == 0)
				temp = std::pow(26,3) * temp;
			else if (i == 1)
				temp = std::pow(26,2) * temp;
			else if (i == 2)
				temp = 26 * temp;
			ret += temp;
		}
	}
	return ret;
}

int main()
{
	cin >> cnt;

	for (int i = 0; i < cnt; ++i)
		cin >> key[i];

	for (int i = 0; i < cnt; ++i)
	{
		memset(arr, 'A', sizeof(arr));
		cout << s(i, 1) << endl;
	}
}