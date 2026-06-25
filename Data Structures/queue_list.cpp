#include <iostream>
using namespace std;

template <typename T>
class queue
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
public:
	queue():mHead(),mTail(),mSize(){}
	~queue(){}

	void push(T data)
	{
		mSize++;
		if (!mHead)
		{
			mHead = new Node();
			mHead->data = data;
			mHead->next = nullptr;
			mTail = mHead;

			return;
		}

		mTail->next = new Node();
		mTail->next->data = data;
		mTail->next->next = nullptr;
		mTail = mTail->next;
	}

	void pop()
	{
		if (empty())
			return;
		mSize--;

		Node* deleteNode = mHead;
		mHead = mHead->next;

		delete deleteNode;
		deleteNode = nullptr;
	}

	bool empty()
	{
		return mHead == nullptr;
	}

	T front()
	{
		return mHead->data;
	}

	void clear()
	{
		while (!empty())
		{
			pop();
		}
	}
private:
	Node* mHead;
	Node* mTail;
	size_t mSize;
};

int main()
{
	queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);

	cout << qu.front() << endl;
	qu.pop();
	cout << qu.front() << endl;
	qu.pop();
	cout << qu.front() << endl;
}