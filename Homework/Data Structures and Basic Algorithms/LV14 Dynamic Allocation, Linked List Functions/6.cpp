#include <iostream>
using namespace std;

struct Node
{
	char c;
	Node* next;
};

void Add(Node** node, char c)
{
	if (*node == nullptr)
	{
		*node = new Node(c, nullptr);
		return;
	}

	Node* curr = *node;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new Node(c, nullptr);

}

char PrintLast(const Node* node)
{
	if (node->next == nullptr)
		return node->c;

	return PrintLast(node->next);
}

void Remove(Node** node)
{
	if (*node == nullptr)
	{
		return;
	}
	Remove(&((*node)->next));
	delete *node;
	*node = nullptr;
}

int main()
{

	Node* head{};

	for (int i = 0; i < 5; ++i)
	{
		char c{};
		cin >> c;
		Add(&head, c);
	}
	cout << PrintLast(head);
	Remove(&head);
	int a{};
}