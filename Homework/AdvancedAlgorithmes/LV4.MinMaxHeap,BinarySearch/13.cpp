#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string str{};
	cin >> str;

	int ret = -1;
	int cnt{};
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '#')
		{
			ret = max(ret, cnt);
			cnt = 0;
		}
		else
		{
			cnt++;
		}
	}
	if (cnt != 0)
		ret = max(ret, cnt);
	for (int i = 0; i < ret; ++i)
		cout << "~";
}