#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;


int main()
{
	string str{};
	int cnt{};

	cin >> str;
	cin >> cnt;
	
	std::sort(str.begin(), str.end());
	vector<int> v(26, 0);

	for (int i = str.size() - cnt; i < str.size(); ++i)
	{
		v[str[i] - 'A']++;
	}

	int maxIndex{};
	int maxVal{};
	for (int i = 0; i < v.size(); ++i)
	{
		if (maxVal < v[i])
		{
			maxVal = v[i];
			maxIndex = i;
		}
	}

	cout << (char)(maxIndex+'A');
}