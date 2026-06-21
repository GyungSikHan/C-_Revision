#include <iostream>
#include <list>
using namespace std;

namespace ya
{
	template <typename T>
   class list
	{
	public:
		struct Node
		{
			T data;
			Node* back;
		};

		struct iterator
		{
			Node* p;

			bool operator!=(const iterator& other) const
			{
				return p->data != other.p->data;
			}
			void operator++()
			{
				if (p->back != nullptr)
					p = p->back;
			}
			T operator*()
			{
				return p->data;
			}

			iterator(Node* d)
			{
				p = d;
			}
		};

		list() :mHead(), mTail() {}
		~list()
		{
		}

		Node* begin()
		{
			return mHead;
		}

		Node* end()
		{
			return mTail->back;
		}

		void push_back(T data)
		{
			if (mHead == nullptr)
			{
				mHead = new Node();
				mHead->data = data;
				mHead->back = new Node();
				mTail = mHead;
			}
			else
			{
				mTail->back = new Node();
				mTail->back->data = data;
				mTail->back->back = new Node();
				mTail = mTail->back;
			}
		}

		void push_front(T data)
		{
			if (mHead != nullptr)
			{
				Node* temp = new Node();
				temp->data = data;
				temp->back = mHead;

				mHead = temp;
			}

		}

	private:
		Node* mHead;
		Node* mTail;
	};
}

int main()
{
	ya::list<int> intList;

	intList.push_back(1);
	intList.push_back(2);
	intList.push_front(3);

	std::list<int> stdList;
	stdList.push_back(1);
	stdList.push_back(2);

	for (ya::list<int>::iterator iter = intList.begin(); iter != intList.end(); ++iter )
	{
		cout << (*iter) << endl;
	}
}