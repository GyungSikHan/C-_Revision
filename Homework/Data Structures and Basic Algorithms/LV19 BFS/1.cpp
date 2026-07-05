#include <iostream>
#include <queue>
using namespace  std;

void BFS(const string& s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			cout << s[i];
	}
}

void DeleteShap(string& s)
{
	string temp{};

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i]  != '#')
			temp += s[i];
	}

	s = temp;
}

int main()
{
	string s{};
	cin >> s;

	DeleteShap(s);

	BFS(s);
}