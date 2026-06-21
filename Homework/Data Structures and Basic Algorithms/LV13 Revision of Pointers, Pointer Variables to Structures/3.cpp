#include <iostream>
using namespace std;

struct Robot
{
	int a;
	int b;
	char t[256];
};

int main()
{
	Robot robert;

	Robot* p = &robert;

	cin >> p->a >> p->b >> p->t;
	cout << p->a + p->b << " " << p->t << endl;
}