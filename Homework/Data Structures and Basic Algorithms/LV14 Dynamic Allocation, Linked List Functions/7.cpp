#include <iostream>
using namespace std;

struct Node
{
	string name;
	Node* Love1;
	Node* Love2;
};

int main()
{
	Node* head = new Node("boss", nullptr, nullptr);
	head->Love1 = new  Node("wife", nullptr, nullptr);
	head->Love2 = new Node("son", nullptr, nullptr);
	head->Love1->Love1 = head;
	head->Love1->Love2 = head->Love2;
	head->Love2->Love1 = new Node("girlfriend", nullptr, nullptr);
	head->Love2->Love1 = new Node("girlfriend", nullptr, nullptr);
	head->Love2->Love2 = new Node("boyfriend", nullptr, nullptr);
	head->Love2->Love1->Love1 = head->Love2;
	head->Love2->Love1->Love2 = head->Love2->Love2;
	head->Love2->Love2->Love1 = head->Love2->Love1;

	cout << head->Love2->Love1->name << " " << head->Love2->Love2->name << endl;

	delete head->Love2->Love2;
	head->Love2->Love2 = nullptr;
	delete head->Love2->Love1;
	head->Love2->Love1 = nullptr;
	delete head->Love2;
	head->Love2 = nullptr;
	delete head->Love1;
	head->Love1 = nullptr;
	delete head;
	head = nullptr;
}