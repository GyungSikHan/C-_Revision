#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

int main()
{
	Node* head;
	Node n1;
	Node n2;
	Node n3;

	head = &n1;
	n1.next = &n2;
	n2.next = &n3;

	n1.data = 1;
	n2.data = 2;
	n3.data = 3;

	cout << head->data << endl;
	cout << head->next->data << endl;
	cout << head->next->next->data << endl;
}