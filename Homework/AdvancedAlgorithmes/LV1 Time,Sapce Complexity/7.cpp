#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int cnt{};
vector<string> n;

bool compare(string a, string b)
{
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (a.at(i) < b.at(i))
				return true;
			else
				return false;
		}
	}

	return a.size() < b.size();
}

int main()
{
	cin >> cnt;

	n.assign(cnt, "");
	for (int i = 0; i < cnt; ++i)
		cin >> n[i];

	std::sort(n.begin(), n.end(), compare);

	for (const string& s : n)
		cout << s << endl;
}