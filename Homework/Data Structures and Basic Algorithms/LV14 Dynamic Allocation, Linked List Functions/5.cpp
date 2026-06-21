#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void Print(Node* node)
{
	if (node == nullptr)
		return;

	cout << node->data << " ";
	Print(node->next);
}

void Add(Node** node, int data)
{
	if (*node == nullptr)
	{
		*node = new Node{};
		(*node)->data = data;
	}
	else
	{
		Node* curr = (*node);
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next= new Node();
		curr->next->data = data;
	}
}

void Remove(Node* node)
{
	if (node == nullptr)
		return;

	Remove(node->next);
	delete node;
	node = nullptr;
}

int main()
{
	Node* head{};
	Add(&head, 3);
	Add(&head, 5);
	Add(&head, 4);
	Add(&head, 2);
	Print(head);
	Remove(head);
}