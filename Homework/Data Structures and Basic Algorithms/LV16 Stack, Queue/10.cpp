#include <iostream>

#include "queue.h"
#include "stack.h"
using namespace std;

bool Solution(const string& str)
{
	Homework::stack<char>st;

	for (int i = 0; i < str.size(); ++i)
	{
		const char c = str.at(i);
		if (st.empty() && c == '>')
			return false;
		else if (st.empty() && c == '<')
			st.push(c);
		else if (c == '>' || c == '<')
		{
			const char c2 = st.top();
			if (c == c2 && c == '>')
				return false;
			else if (c == c2 && c == '<')
				st.push(c);
			else if (c != c2)
				st.pop();
		}
	}

	return true;
}

int main()
{
	string str{};
	cin >> str;

	cout << (Solution(str) ? "정상" : "비정상") << endl;
}