#include <iostream>
using namespace std;

int main()
{
	string s{};
	cin >> s;
	bool bFlag{};
	while (!bFlag)
	{
		int cnt{};
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '_')
			{
				cnt++;
				continue;
			}
			s[i] -= 1;
			if (s[i] < 'A')
			{
				s[i] = '_';
				cnt++;
			}
		}

		cout << s<<endl;
		if (cnt == (int)s.size())
			bFlag = true;
	}
}