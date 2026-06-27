#include <iostream>
using namespace std;

int ret[26]{};
int num[26]{-1,};

void Counts(const string& s)
{
	for (int i = 0; i < strlen(s.c_str()); ++i)
	{
		ret[s.at(i) - 'a']++;
		if (num[s.at(i) - 'a'] == 0)
			num[s.at(i) - 'a'] = i;
	}
}

int Check(const string& s)
{
	int minIdx = 987654321;
	for (int i = 0; i < 26; ++i)
	{
		if (ret[i] == 1)
		{
			minIdx = std::min(minIdx, num[i]);
		}
	}

	return minIdx;
}

int main()
{
	string s{};
	cin >> s;
	Counts(s);
	int idx = Check(s);
	if (idx == 987654321)
		cout << "";
	else
		cout << s[idx];
}