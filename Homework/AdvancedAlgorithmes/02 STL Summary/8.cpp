#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int n{};
vector<string> v;

void Check(string& str)
{
	int upper{};
	int lower{};
	bool bFlag{};
	for (int i = 1; i < str.size(); ++i)
	{
		if (isupper(str[i]))
		{
			bFlag = true;
			break;
		}
	}
	
	if (bFlag)
		for (char& ch : str)
			ch = static_cast<char>(std::toupper(ch));
	else
		str[0] = static_cast<char>(std::toupper(str[0]));
}


int main()
{
	cin >> n;
	v.assign(n, "");
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 0; i < n; ++i)
		Check(v[i]);

	sort(v.begin(), v.end(), [](const string& a, const string& b)
	{
		int size = static_cast<int>(a.size() < b.size() ? a.size() : b.size());

		for (int i = 0; i < size; ++i)
		{
			char temp = static_cast<char>(toupper(a[i]));
			char temp2 =static_cast<char>(toupper(b[i]));

			if (temp < temp2)
				return true;
			else if (temp > temp2)
				return false;
		}

		return true;
	});

	for (const string& iter : v)
		cout << iter << endl;
}