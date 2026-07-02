#include <iostream>
#include <string>

using namespace std;

int MyAtoi(const string& s)
{
	if (s[0] >= 'a' && s[0] <='z')
		return 0;
	int ret{};
	char symbol{};

	for (int i = 0; i < s.size(); ++i)
	{
		char temp = s.at(i);

		if (ret == 0 && temp == '0' && (s.at(i+1) < '0' || s.at(i+1)> '9'))
			break;
		if (temp == '-' || temp == '+')
			symbol = temp;
		else if (temp < '0' || temp > '9' && temp != 0)
			break;
		else if (temp >= '0' && temp <= '9')
		{
			ret += (temp - '0');
			ret *= 10;
		}
	}

	if (symbol == '-')
		ret *= -1;
	ret /= 10;

	return ret;
}

int main()
{
	string s{};
	getline(cin, s);
	cout<<MyAtoi(s);
}