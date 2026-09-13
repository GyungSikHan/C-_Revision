#include <iostream>

using namespace std;

string str{};
string arr[5]
{
	{"BTS"},
	{"SBS"},
	{"BS"},
	{"CBS"},
	{"SES"}
};
int ret = 987654321;

void DFS(string temp, int level)
{
	if (str.size() < temp.size())
		return;

	if (str == temp)
	{
		ret = min(ret, level);
		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		DFS(temp + arr[i], level + 1);
	}
}

int main()
{
	cin >> str;
	DFS("", 0);
	cout << (ret != 987654321 ? ret : -1);
}