#include <iostream>
using namespace std;

int main()
{
	char arr[256]{};
	char str[256]{};
	cin >> str;

	int idx{};
	while (str[idx] != '\0')
	{
		arr[str[idx]]++;
		idx++;
	}

	for (int i = 'A'; i < 'Z'; ++i)
	{
		if (arr[i] != 0)
			cout << (char)i;
	}
}