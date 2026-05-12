#include <iostream>
using namespace std;

void DAT(const char* str, int* ret)
{
	int idx{};
	while (str[idx] != '\0')
	{
		ret[str[idx++]]++;
	}
}

bool Solve(const int* ret)
{
	for (int i = 'A'; i <= 'Z'; ++i)
	{
		if (ret[i] >= 2)
			return false;
	}
	return true;
}

int main()
{
	char str[256]{};
	int ret[100]{};
	for (int i = 0; i < 3; ++i)
	{
		cin >> str;
		DAT(str, ret);
	}
	bool bFlag = Solve(ret);
	if (bFlag)
		cout << "Perfect";
	else
		cout << "No";
}

