#include <iostream>
using namespace std;
char tree[256] = " TBECD";

void run(int now, int level)
{
	if (tree[now] == '\0')
		return;

	cout << tree[now];
	run(now * 2, level + 1);
	run(now * 2 + 1, level + 1);
}
int main()
{
	run(1, 0);
}