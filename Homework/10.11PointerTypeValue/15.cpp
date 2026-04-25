#include <iostream>

using namespace std;

int main()
{
	int a{};
	char gd{};
	cin >> a >> gd;

	int* p = &a;
	char* t = &gd;

	cout << *p << endl;
	cout << *t << endl;

	*p = 10;
	*t = 'B';
	cout << *p << endl;
	cout << *t << endl;
	(*p)++;
	cout << *p << endl;
}