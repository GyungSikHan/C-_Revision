#include <iostream>
using namespace std;

void ChangeValue(int** ptr)
{
	**ptr = 500;
}

void ChangePointer(int** ptr, int* newTarget)
{
	*ptr = newTarget;
}

int main()
{
	int a = 100;
	int b = 300;
	int* p = &a;
	cout << "init: " << *p << endl;
	
	ChangeValue(&p);
	cout << "Change Value: " << *p << endl;
	
	ChangePointer(&p, &b);
	cout << "Change Pointer: " << *p << endl;
}