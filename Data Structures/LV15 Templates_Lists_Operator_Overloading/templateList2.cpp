#include <iostream>
using namespace std;

namespace ym
{
	template <typename T>
	class list
	{
	private:
		struct Node
		{
			T data;
			Node* next;
		};

	public:
		list() :mHead(), mTail() {}
		void push_back(T data)
		{
			if (!mHead)
			{
				mHead = new Node();
				mHead->data = data;
				mTail = mHead;
			}
			else
			{
				mTail->next = new Node();
				mTail->next->data = data;
				mTail = mTail->next;
			}
		}

		void print()
		{
			Node* temp = mHead;
			while (temp != nullptr)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	private:
		Node* mHead;
		Node* mTail;
	};
}

int main()
{
	ym::list<int> intList;
	intList.push_back(1);
	intList.push_back(2);
	intList.push_back(3);
	intList.print();

	ym::list<float> floatList;
	floatList.push_back(1.1f);
	floatList.push_back(2.1f);
	floatList.push_back(2.1f);
	floatList.print();
}