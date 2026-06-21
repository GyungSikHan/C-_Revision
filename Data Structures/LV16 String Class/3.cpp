#include <iostream>
#include <list>
using namespace std;

template <typename T>
class ListNode
{
public:

	ListNode()
		:data(),next()
	{
	}
	void operator=(const ListNode& other)
	{
		data = other.data;
		next = other.next;
	}
	void push(int amount)
	{
		if (next == nullptr)
		{
			data = amount;
		}
	}
private:
	ListNode* head;
	ListNode* next;
	T data;
};

int main()
{
	list<int> head;
	head.push_back(1);
	head.push_back(2);
	head.push_back(3);
	head.push_back(4);
	head.push_back(5);

	list<int>* p{};
	list<int>* q{};
	list<int>* r = &head;
	
	while (r != nullptr)
	{
		p = q;
		q = r;
		r = r++;

		q++;
		r++;
		q = p;
	}
}