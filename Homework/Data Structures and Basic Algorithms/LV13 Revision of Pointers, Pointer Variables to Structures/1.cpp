#include <iostream>
using namespace std;

struct Node
{
	Node* next;
	int data;
};

int main()
{
	Node a;
	Node b;
	Node c;
	c.data = 3;
	Node t;
	Node g;
	g.data = 9;
	Node f;
	f.data = 6;
	Node k;
	Node p;

	a.next = &b;
	b.next = &c;
	f.next = &b;
	p.next = &k;
	k.next = &f;

	cout << &a << endl; // a의 값 <--- 예시정답
	cout << &k << endl; // k의 값
	cout << &t << endl; // t의 값
	cout << &c << endl; // c의 주소
	cout << a.next << endl; // *a
	cout << p.next->next << endl; // **p
	cout << &k << endl; // &k
	cout << p.next << endl; //*p

}