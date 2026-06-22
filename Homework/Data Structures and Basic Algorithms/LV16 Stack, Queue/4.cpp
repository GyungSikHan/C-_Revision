#include <iostream>

#include "queue.h"
#include "vector.h"
using namespace std;

struct Node
{
public:
	Node():a(),b(),p(){}
	Node(char a, int b, Node* p)
		:a(a),b(b),p(p)
	{
		
	}
	char a;
	int b;
	Node* p;
};

int main()
{
	Node* node{};
	Node* tail{};

	int len{};
	cin >> len;

	for (int i = 0; i < len; ++i)
	{
		Node* temp = new Node((char)('A' + i), i + 1, nullptr);

		if (node == nullptr)
		{
			node = temp;
			tail = temp;
		}
		else
		{
			tail->p = temp;
			tail = tail->p;
		}
	}

	Node* temp = node;
	for (int i = 0; i < len; ++i)
	{
		cout << temp->a << " ";
		temp = temp->p;
	}
	cout << endl;
	temp = node;
	while (temp != nullptr)
	{
		cout << temp->b << " ";
		temp = temp->p;
	}
}