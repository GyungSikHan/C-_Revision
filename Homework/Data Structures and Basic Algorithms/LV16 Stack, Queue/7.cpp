#include <iostream>
using namespace std;

struct Node
{
	int x;
	char y;
};

template <typename T>
class queue
{
public:
	queue():mNode(new Node[DEFAULT_CAPACITY]),mSize(), mCapacity(DEFAULT_CAPACITY){}
	~queue()
	{
		delete[] mNode;
		mSize = 0;
		mCapacity = 0;
	}

	void push(Node* data)
	{
		mNode[mSize++] = *data;
	}

	void Print()
	{
		for (int i = 0; i < mSize; ++i)
		{
			cout << mNode[i].x << " " << mNode[i].y << endl;
		}
	}
private:
	static const size_t DEFAULT_CAPACITY = 10;
	Node* mNode;
	size_t mSize;
	size_t mCapacity;
};

int main()
{
	int input{};
	cin >> input;
	
	queue<int> qu;
	for (int i = 0; i < input; ++i)
	{
		Node node;
		cin >> node.x >> node.y;

		qu.push(&node);
	}

	qu.Print();
}