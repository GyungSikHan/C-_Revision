#include <iostream>
using namespace std;

char value[10] = "TEQWA";
int map[5][5]
{
	{0,1,0,0,0},
	{0,0,1,1,0},
	{0,0,0,0,0},
	{1,0,0,0,1},
	{0,0,0,0,0}
};
int visited[10]{};
char path[10]{};

void run(int now, int level)
{
	cout << value[now];
	for (int i = 0; i < 5; ++i)
	{
		if (map[now][i] == 1 && visited[i] == 0)
		{
			path[level + 1] = value[i];
			visited[i] = 1;
			run(i, level + 1);
			path[level + 1] = 0;
		}
	}
}

int main()
{
	path[0] = 'T';
	visited[0] = 1;
	run(0, 0);
}