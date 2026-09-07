#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	string str{};
	cin >> str;

	std::priority_queue<char, std::vector<char>>qu;
	for (int i = 0; i < str.size(); ++i)
	{
		qu.push(str[i]);
	}

	int size = qu.size();
	for (int i = 0; i < size; ++i)
	{
		cout << qu.top();
		qu.pop();
	}
}