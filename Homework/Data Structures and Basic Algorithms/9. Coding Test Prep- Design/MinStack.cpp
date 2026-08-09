#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
private:
	struct Node
	{
		int data;
		Node* next;
	};
public:
	MinStack()
		:mTop(-1), node(),mMin()
	{
		
	}
	~MinStack()
	{
		while (mTop != -1)
		{
			Node* curr = node;
			node = curr->next;

			delete curr;
			curr = nullptr;
			mTop--;
		}
	}
	void push(int val)
	{
		if (mTop == -1)
		{
			node = new Node;
			node->data = val;
			node->next = nullptr;
		}
		else
		{
			Node* curr = node;
			for (int i = 0; i < mTop; ++i)
				curr = curr->next;
			curr->next = new Node;
			curr = curr->next;
			curr->data = val;
			curr->next = nullptr;
		}
		
		mTop++;
		mMin.push_back(val);

		sort(mMin.begin(), mMin.end());
	}
	void pop()
	{
		if (mTop == -1)
			return;

		Node* curr = node;
		for (int i = 0; i < mTop-1; ++i)
			curr = curr->next;

		mTop--;
		Node* next = curr->next;
		int temp = next->data;
		curr->next = nullptr;
		
		auto iter = find(mMin.begin(), mMin.end(), temp);
		mMin.erase(iter, iter + 1);
		sort(mMin.begin(), mMin.end());
		delete next;
		next = nullptr;
	}
	int top()
	{
		Node* curr = node;
		for (int i = 0; i < mTop; ++i)
			curr = curr->next;

		return curr->data;
	}
	int getMin()
	{
		return mMin[0];
	}

private:
	int mTop;
	Node* node;
	vector<int> mMin;
};

int main()
{
	MinStack st;

	st.push(-2);
	st.push(0);
	st.push(-3);
	cout << st.getMin() << endl;
	st.pop();
	cout << st.top() << endl;
	cout << st.getMin() << endl;
}
