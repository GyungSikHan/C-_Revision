#include <iostream>

using namespace std;

void Swap(int* a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int num1 = 100;
	int num2 = 200;

	Swap(&num1, &num2);

	return 0;
}