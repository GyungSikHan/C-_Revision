#include <iostream>
using namespace std;

bool CheckStr(const string& needle, const string& haystack, int startIdx)
{
	for (int i = 0; i < haystack.size(); ++i)
	{
		if (needle[startIdx] != haystack[i])
			return false;
		startIdx++;
	}
	return true;
}

int StrStr(const string& needle, const string& haystack)
{
	for (int i = 0; i < needle.size(); ++i)
	{
		if (CheckStr(needle, haystack, i))
			return i;
	}

	return -1;
}

int main()
{
	string needle{}, haystack{};
	cin >> needle >> haystack;

	cout<<StrStr(needle, haystack);
}