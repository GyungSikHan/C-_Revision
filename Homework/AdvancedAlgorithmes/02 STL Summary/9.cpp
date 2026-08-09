#include <iostream>
#include <algorithm>

using namespace std;

int n{};
string str{};
int ret[26]{};

string SelectStr()
{
	string temp{};
	for (int i = (int)str.size() - 1; i >= 0; --i)
		temp += str[i];

	return temp;
}

void CountArray(const string& temp)
{
	for (int i = 0; i < temp.size(); ++i)
		ret[temp[i] - 'A']++;
}

char SerchResult()
{
	int idx{};
	int Max = -1;
	for (int i = 0; i < 26; ++i)
	{
		if (Max < ret[i])
		{
			Max = ret[i];
			idx = i;
		}
	}

	return (char)idx + 'A';
}

int main()
{
	cin >> str;
	cin >> n;

	sort(&(str[0]), &(str[0]) + str.size());
	string temp = SelectStr();
	CountArray(temp);	

	cout << SerchResult();
}