#include <iostream>
using namespace std;

struct Node
{
	char c;
	Node* next1;
	Node* next2;
};

int main()
{
	Node* head = new Node('A',nullptr,nullptr);
	head->next1 = new Node('B', nullptr, nullptr);
	head->next1->next1 = new Node('D', nullptr, nullptr);
	head->next1->next2 = new Node('E', nullptr, nullptr);
	head->next2 = new Node('C', nullptr, nullptr);

	char str[256]{};
	cin >> str;

	Node* curr{};
	for (int i = 0; i < strlen(str); ++i)
	{
		switch (str[i])
		{
		case 'H':
			curr = head;
			break;
		case 'L':
			curr = curr->next1;
			break;
		case 'R':
			curr = curr->next2;
			break;
		}
	}

	cout << curr->c;

	delete head->next2;
	head->next2 = nullptr;
	delete head->next1->next2;
	head->next1->next2 = nullptr;
	delete head->next1->next1;
	head->next1->next1 = nullptr;
	delete head->next1;
	head->next1 = nullptr;
	delete head;
	head = nullptr;
}