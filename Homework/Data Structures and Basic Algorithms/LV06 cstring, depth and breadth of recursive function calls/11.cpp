#include <iostream>
using namespace std;

void Solve(char* str, const char a, int idx)
{
	if (str[idx] == '\0')
		return;

	if (str[idx] == a)
	{
		str[idx - 1] = '#';
		str[idx + 1] = '#';
	}
	else
		Solve(str, a, idx + 1);
}

int main()
{
	char str[256]{};
	char a[2];
	cin >> str;
	for (int i = 0; i < 2; ++i)
	{
		char a{};
		cin >> a;

		Solve(str, a, 0);
	}

	cout << str;
}