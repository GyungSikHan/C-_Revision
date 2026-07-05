#include <iostream>
using namespace std;

char value[6]{ "TBECD" };
char path[6]{};

int map[5][5]
{
	0,1,1,0,0,
	0,0,0,1,1,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0
};

void run(int now, int level)
{
	cout << value[now];
	for (int i = 0; i < 5; ++i)
	{
		if (map[now][i] == 1)
		{
			path[level + 1] = value[i];
			run(i, level + 1);
			path[level + 1] = 0;
		}
	}
}

int main()
{
	path[0] = value[0];
	run(0, 0);
}