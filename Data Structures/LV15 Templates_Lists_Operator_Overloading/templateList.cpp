#include <iostream>
#include <list>
using namespace std;
namespace ya
{
	template <typename T>
   class List
	{
	private:
		struct Node
		{
			Node* next;
			T data;
		};

	public:
		List()
			:mHead(),mTail()
		{
		}
		void push_back(T data)
		{
			if (mHead == nullptr)
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
			int count= 0;
			Node* temp = mHead;
			while (temp != nullptr)
			{
				cout << "Index: "<<count++<<" Data: " <<temp->data << endl;
				temp = temp->next;
			}
		}
	private:
		Node* mHead;
		Node* mTail;
	};
}

int main()
{
	ya::List<int> intList;
	intList.push_back(1);
	intList.push_back(2);
	intList.push_back(3);
	intList.print();

	ya::List<float> floatList;
	floatList.push_back(1.3f);
	floatList.push_back(2.3f);
	floatList.push_back(3.3f);
	floatList.print();
}