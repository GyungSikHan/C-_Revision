#include <iostream>
using namespace std;

int main()
{
	int a{}, b{};
	cin >> a >> b;

	int* p = &a;
	int* t = &b;

	int temp = *p;
	*p = *t;
	*t = temp;

	cout << a <<" "<< b << endl;
}