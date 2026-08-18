//Union Find2
#include <iostream>

using namespace std;

char parent[1000];

char getParent(char x)
{
	if (parent[x] == 0)
		return x;

	int ret = getParent(parent[x]);
	parent[x] = ret;

	return ret;
}

void BindGroup(char ch1, char ch2)
{
	int a = getParent(ch1);
	int b = getParent(ch2);

	if (a != b)
		parent[b] = a;
}

int main()
{
	BindGroup('A', 'C');
	BindGroup('C', 'D');

	BindGroup('A', 'G');
	BindGroup('H', 'C');
	BindGroup('A', 'H');
	BindGroup('F', 'D');
	BindGroup('A', 'F');
}