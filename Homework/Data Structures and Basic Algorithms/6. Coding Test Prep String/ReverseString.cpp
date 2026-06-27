#include<iostream>
using namespace std;

#define MAX_LEN 106

void Reverse(const char* s, char* ret)
{
	int idx{};
	int i = std::strlen(s) - 1;
	for (i ; i >= 0; --i)
	{
		ret[idx++] = s[i];
	}
}

int main()
{
	char s[MAX_LEN]{};
	cin >> s;
	char ret[MAX_LEN]{};

	Reverse(s, ret);
	cout << ret;
}