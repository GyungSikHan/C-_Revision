#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n)
{
	if (n == 1)
		return "1";

	string s = countAndSay(n - 1);
	
	string ret{};
	char data = -1;
	int count{};
	for (int i = 0; i < s.size();i++)
	{
		if (data == -1)
		{
			data = s[i];
			count++;
		}
		else
		{
			if (data == s[i])
				count++;
			else
			{
				ret += std::to_string(count) + data;
				count = 1;
				data = s[i];
			}
		}
	}

	if (data != -1)
	{
		ret += std::to_string(count) + data;
	}

	return ret;
}

int main()
{
	int n{};
	cin >> n;

	cout<<countAndSay(n);
}