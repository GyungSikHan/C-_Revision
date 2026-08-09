#include <iostream>

using namespace std;

string str[6]
{
	"ABCD",
	"ABCE",
	"AGEH",
	"EIEI",
	"FEQE",
	"ABAD"
};
string s;

struct Monja
{
	bool b[4];
	char c[4];
	int cnt;
};

int main()
{
	Monja m{};
	cin >> s;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '?')
			continue;

		m.b[i] = 1;
		m.c[i] = s[i];
		m.cnt++;
	}

	int ret{};
	for (int i = 0; i < 6; ++i)
	{
		int cnt{};
		for (int j = 0; j < 4; ++j)
		{
			if (m.b[j] == 0)
				continue;

			if (str[i][j] == m.c[j])
				cnt++;
		}

		if (cnt == m.cnt)
			ret++;
	}

	cout << ret;
}