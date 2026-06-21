#include <iostream>
using namespace std;

template <typename T>
class stack
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
public:
	stack():mSize(), mNode(){}
	~stack()
	{
		clear();
	}

	void push(T data)
	{
		mSize++;
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = mNode;

		mNode = newNode;
	}

	void pop()
	{
		if (empty())
			return;

		Node* deleteNode = mNode;
		mNode = mNode->next;

		delete deleteNode;
		deleteNode = nullptr;
		mSize--;
	}

	T top()
	{
		if (empty())
			return -1;
		return mNode->data;
	}

	bool empty()
	{
		return (mSize == 0);
	}

	void clear()
	{
		while (mSize != 0)
			pop();
	}
private:
	size_t mSize;
	Node* mNode;
};

int main()
{
	stack<int> st;
	st.push(3);
	st.push(5);
	st.push(4);

	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
}