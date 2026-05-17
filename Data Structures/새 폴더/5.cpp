#include <iostream>

using namespace std;

void BBQ(int level)
{
	if (level == 2)
		return;

	BBQ(level+1);
	BBQ(level+1);
}
int main()
{
	BBQ(0);
}