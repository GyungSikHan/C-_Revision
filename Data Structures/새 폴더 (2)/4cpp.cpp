#include <iostream>
using namespace std;

char path[5]{};
int visited[5]{};

void Test(int level)
{
	if (level == 3)
	{
		cout << path<< endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (visited[i] == 1)
			continue;

		visited[i] = 1;
		path[level] = 'A' + i;
		Test(level + 1);

		path[level] = 0;
		visited[i] = 0;
	}
}
int main()
{
	Test(0);
}