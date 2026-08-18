//Union Find
#include <iostream>
using namespace std;

int name[256]{};
int n{};
int group[256]{};
int gCnt{};

void insert(char ch1, char ch2)
{
	if (group[ch1] == 0)
		name[n++] = ch1;
	if (group[ch2] == 0)
		name[n++] = ch2;

	if (group[ch1] != 0 && group[ch2] == 0)
		group[ch2] = group[ch1];
	else if (group[ch1] == 0 && group[ch2] != 0)
		group[ch1] = group[ch2];
	else if (group[ch1] == 0 && group[ch2] == 0)
	{
		gCnt++;
		group[ch1] = gCnt;
		group[ch2] = gCnt;
	}
	else
	{
		int g = group[ch2];
		for (int i = 0; i < n; ++i)
		{
			if (group[name[i]] == g)
				group[name[i]] = group[ch1];
		}
	}
}

int main()
{
	insert('A', 'B');
	insert('A', 'C');

	insert('E', 'Q');
	insert('E', 'F');

	insert('F', 'A');
}