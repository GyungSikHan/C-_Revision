#include <iostream>
using namespace std;

void Test(int* a, int* b)
{
	*a = 10;
	*b = 20;
}

int main()
{
	int a = 1;
	int b = 2;

	Test(&a, &b);
}