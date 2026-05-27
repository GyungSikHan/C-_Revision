#include <iostream>
using namespace std;

void Recursion(int currDepth)
{
	cout <<currDepth << endl;

	if (2 == currDepth)
		return;
	
	for (int i = 1; i <= 3; ++i)
	{
		Recursion(currDepth + 1);
	}
}

int main()
{
	Recursion( 0);
}