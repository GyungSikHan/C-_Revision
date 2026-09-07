#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n{};
vector<int> v;

bool IsBinaryTree()
{
	for (int i = n; i > 1; --i)
	{
		if (v[i] == -1)
			continue;
		if (i % 2 == 1 && v[i] < v[i / 2])
			return false;
		else if (i % 2 == 0 && v[i] > v[i / 2])
			return false;
	}

	return true;
}

int main()
{
	cin >> n;
	v.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		string s{};
		cin >> s;
		if (s == "null")
			v[i] = -1;
		else
			v[i] = stoi(s);
	}

	cout << (IsBinaryTree() ? "true" : "false");
}