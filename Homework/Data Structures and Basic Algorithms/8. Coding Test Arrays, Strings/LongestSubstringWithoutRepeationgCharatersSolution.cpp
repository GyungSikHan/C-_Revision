#include <algorithm>
#include <iostream>
#include <vector> 
#include <stack>
using namespace std;

void Solution(vector<char>& ret, const string& s)
{
	stack<char> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (st.empty())
			st.push(s[i]);
		else
		{
			vector<char >temp;
			int size = st.size();
			bool bFlag{};
			for (int j = 0; j < size; j++)
			{
				if (st.top() == s[i])
				{
					bFlag = true;
					break;
				}
				temp.push_back(st.top());
				st.pop();
			}
			if (bFlag)
			{
				int size = st.size();
				for (int j = 0; j < size; j++)
				{
					ret.push_back(st.top());
					st.pop();
				}
			}
			for (int j = 0; j < temp.size(); ++j)
				st.push(temp[j]);
		}
	}
}

int main()
{
	vector<char> ret;
	string s{};
	cin >> s;
	Solution(ret, s);

	sort(ret.begin(), ret.end(), std::greater<int>());

	cout << ret[0];
}