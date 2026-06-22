#include <iostream>

#include "queue.h"
using namespace std;

int main()
{
	char h[4]{ 'B','I','A','H' };
	int cnt{};
	int idx{};
	bool visited[4]{};
	Homework::queue<char> node;
	Homework::queue<char> ret;

	while (cnt != 4)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (idx >= 4)
				idx -= 4;
			if (visited[idx])
			{
				i--;
				idx++;
				continue;
			}
			node.push(h[idx]);
			idx++;
		}

		if (idx >= 4)
			idx -= 4;
		while (visited[idx])
		{
			idx++;
			if (idx >= 4)
				idx -= 4;
		}
		ret.push(h[idx]);
		visited[idx] = true;
		cnt++;
	}

	for (auto iter = ret.begin(); iter != ret.end(); ++iter)
		cout << (*iter) << " ";
}