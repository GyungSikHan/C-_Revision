#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void Add(Node** node, int data)
{
	if (*node == nullptr)
	{
		*node = new Node(data, nullptr);
		return;
	}

	Node* curr = *node;
	while (curr->next)
	{
		curr = curr->next;
	}

	curr->next = new Node(data,nullptr);
}

int SerchData(const Node* node, int index, int count)
{
	if (index == count)
		return node->data;

	return SerchData(node->next, index, count+1);
}

void Remove(Node** node)
{
	if (*node == nullptr)
		return;
	Remove(&((*node)->next));
	delete* node;
	*node = nullptr;
}

int main()
{
	int n{};
	cin >> n;

	Node* head{};
	while (n != 0)
	{
		Add(&head, n % 10);
		n /= 10;
	}
	int sum{};
	sum	= 10*SerchData(head, 3, 0);
	sum += SerchData(head, 1, 0);
	cout << sum + 5;
	Remove(&head);
	
}