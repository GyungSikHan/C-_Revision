#include <iostream>
using namespace std;

char path[10]{};
char name[10] = "ABC";

void run(int level)
{
	if (level == 2)
	{
		cout << path << endl;
		cout << endl;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		path[level] = name[i];
		run(level + 1);
		path[level] = 0;
	}
}

int main()
{
	run(0);
}