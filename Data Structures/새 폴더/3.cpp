#include <iostream>
using namespace std;

void Test(int x)
{
	if (x == 3)
		return;
	Test(x + 1);
	cout << x << endl;
}

int main()
{
	Test(0);
}