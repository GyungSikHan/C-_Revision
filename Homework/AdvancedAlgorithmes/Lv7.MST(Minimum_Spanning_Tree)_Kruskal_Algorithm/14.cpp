#include <iostream>
#include <vector>

using namespace std;

const int MAX_COUNT = 4;
const int MAX = 987654321;

string meat{};
int ret = MAX;

void Print(const string& temp)
{
	cout << temp << endl;
}

bool Check(const string& temp)
{
	char c = temp[0];
	for (int i = 1; i < temp.size(); ++i)
	{
		if (c != temp[i])
			return false;
	}

	return true;
}

bool Reverse(const vector<int> indeces)
{
	string temp = meat;
	for (const int& idx : indeces)
	{
		for (int i = idx-1; i <= idx+1; ++i)
		{
			if (i < 0 || temp.size() <= i)
				continue;

			temp[i] = (temp[i] == 'O' ? 'X' : 'O');
		}
	}
	//Print(temp);
	return Check(temp);
}

void Solution(int cnt, vector<int>& indeces)
{
	if (MAX_COUNT < cnt)
		return;
	if (cnt != 0)
	{
		if (Reverse(indeces))
		{
			ret = min(ret,cnt);
			return;
		}
	}

	for (int i = 0; i < meat.size(); ++i)
	{
		indeces.push_back(i);
		Solution(cnt + 1, indeces);
		indeces.pop_back();
	}
}

int main()
{
	cin >> meat;
	vector<int> v;
	Solution(0, v);
	if (ret == MAX)
		cout << "impossible";
	else
		cout << ret;
}