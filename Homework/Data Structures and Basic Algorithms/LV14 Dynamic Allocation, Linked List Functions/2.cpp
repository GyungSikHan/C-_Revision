#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char* c1 = new char{};
	char* c2 = new char{};
	char* c3 = new char{};

	cin >> *c1 >> *c2 >> *c3;

	if (isupper(*c1) && isupper(*c2) && isupper(*c3))
		cout << "모두 대문자";
	else
		cout << "소문자 있음";

	delete c1;
	c1 = nullptr;
	delete c2;
	c2 = nullptr;
	delete c3;
	c3 = nullptr;
}