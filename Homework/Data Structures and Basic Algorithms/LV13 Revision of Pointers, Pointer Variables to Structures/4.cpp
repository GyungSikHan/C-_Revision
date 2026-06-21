#include <iostream>
using namespace std;

struct NODE
{
	int x;
	NODE* next;
};

int main()
{
	NODE a;
	NODE b;
	NODE c;

	a.next = &b;
	a.next->next = &c;
	a.x = 3;
	a.next->x = 5;
	a.next->next->x = 4;

	cout << a.x << " " << a.next->x << " " << a.next->next->x << endl;
}