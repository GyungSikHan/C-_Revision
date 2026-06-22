#include <iostream>

#include "queue.h"
#include "stack.h"
using namespace std;

int main()
{
	string parsing{};
	cin >> parsing;
	
	Homework::stack<int> st;

	for (int i = 0; i < parsing.size(); ++i)
		if (parsing[i] >= '0' && parsing[i] <= '9')
			st.push((int)(parsing[i] - '0'));

	int ret{};
	int size = st.size();
	for (int i = 0; i < size; ++i)
	{
		int temp = st.top() * (int)std::pow(10, i);
		ret += temp;
		st.pop();
	}
	cout << ret + 5;
}