#include <iostream>
using namespace std;

string s[3]{};

int Solution(int idx)
{
	int cnt{};
	int ret{};
	for (int i = s[idx].size()-1; i >=0 ; --i)
	{
		if (s[idx][i] == '1')
			ret += static_cast<int >(std::pow(2, cnt));
		
		cnt++;
	}

	return ret;
}

int main()
{
	for (int i = 0; i < 3; ++i)
		cin >> s[i];

	int ret = -1;
	int index{};
	for (int i = 0; i < 3; ++i)
	{
		int temp = std::max(ret,Solution(i));
		if (ret < temp)
		{
			index = i;
			ret = temp;
		}
	}

	cout << s[index] << endl;
}