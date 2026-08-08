#include <iostream>
#include <memory>

struct Node
{
	int value;
	std::shared_ptr<Node> next;
	std::weak_ptr<Node> prev;

	Node(){}
	~Node(){}
};

int main()
{
	auto a = std::make_shared<Node>();
	auto b = std::make_shared<Node>();
	a->value = 1;
	b->value = 2;

	a->next = b;
	b->prev = a;

	if (auto p = b->prev.lock())
		std::cout << "prev value=" << p->value << "\n";
}