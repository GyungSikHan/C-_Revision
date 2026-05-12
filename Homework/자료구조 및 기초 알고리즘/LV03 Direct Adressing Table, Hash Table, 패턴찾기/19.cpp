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

int main()
{
	int ret[100]{};
	char str[256]{};
	cin >> str;

	DAT(str, ret);

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		if (ret[i])
			cout << (char)i;
	}
}