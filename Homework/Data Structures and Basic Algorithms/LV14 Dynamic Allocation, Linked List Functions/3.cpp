#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next1;
	Node* next2;
};

void Print(Node* node, int level)
{
	if (node == nullptr)
		return;

	cout << "level " << level << ": " << node->data << endl;
	Print(node->next1, level+1);
	Print(node->next2, level +1);
}

int main()
{
	Node* head = new Node(3, nullptr, nullptr);
	head->next1 = new Node(7,nullptr,nullptr);
	head->next2 = new Node(6,nullptr,nullptr);
	head->next2->next1 = new Node(2,nullptr,nullptr);

	Print(head, 0);

	delete head->next1;
	head->next1 = nullptr;
	delete head->next2->next1;
	head->next2->next1 = nullptr;
	delete head->next2;
	head->next2 = nullptr;
	delete head;
	head = nullptr;
}