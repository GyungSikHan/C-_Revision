#include <iostream>
using namespace std;

void SWAP(char* p1, char* p2)
{
	char temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	char a{}, b{};
	cin >> a >> b;

	char* p1 = &a, * p2 = &b;

	SWAP(p1, p2);
	cout << *p1 << " " << *p2 << endl;
	cout << a << " " << b << endl;
}