#include <iostream>
using namespace std;

const int length = 200;

int main()
{
	int size{};
	string strs[length]{};

	cin >> size;
	for (int i = 0; i < size; ++i)
		cin >> strs[i];

	string ret{};
	int idx{};
	while (true)
	{
		bool bFlag{};
		char temp{};
		for (int i = 0; i < size; ++i)
		{
			if (strs[i].size() <= idx)
			{
				bFlag = true;
				break;
			}
			if (i == 0)
				temp = strs[i][idx];
			else if (temp != strs[i][idx])
			{
				bFlag = true;
				break;
			}
		}

		if (bFlag)
			break;
		idx++;
		ret += temp;
	}

	cout << ret;
}