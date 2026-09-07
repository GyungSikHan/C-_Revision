#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int length = 5;
vector<int> v;

int Search(const vector<char>& str)
{
	int start = 0, end = str.size();
	int ret{};

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (str[mid] == '*')
		{
			ret = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	return ret+1;
}

void Solution(int idx)
{
	string temp{};
	vector<char> str;

	cin >> temp;

	for (int i = 0; i < temp.size(); ++i)
		if (temp.at(i) == '_' || temp.at(i) == '*')
			str.push_back(temp.at(i));

	sort(str.begin(), str.end());
	
	v[idx] = Search(str);
}

int main()
{
	v.assign(length, 0);
	for (int i = 0; i < length; ++i)
		Solution(i);

	for (const int iter : v)
		cout << iter << endl;
}
