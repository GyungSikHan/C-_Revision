#include <iostream>
using namespace std;
char c[7]{};
void run(int now, int level)
{
	if (c[now] == '\0')
		return;

	cout << c[now];
	run(now * 2, level + 1);
	run(now * 2 + 1, level + 1);
}

int main()
{
	
	int size = 6;

	for (int i = 1; i < size; ++i)
		cin >> c[i];
	run(1, 0);
}