#pragma once

namespace Homework
{
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
		stack() :mTop(), mSize() {}
		~stack()
		{
			clear();
		}

		void push(T data)
		{
			Node* node = new Node;
			node->data = data;
			node->next = mTop;
			mTop = node;
			mSize++;
		}
		void pop()
		{
			Node* node = mTop;
			mTop = node->next;
			mSize--;
			delete node;
			node = nullptr;
		}
		void clear()
		{
			while (mSize != 0)
				pop();
		}

		T& top()
		{
			return mTop->data;
		}
		size_t size()
		{
			return mSize;
		}

		bool empty()
		{
			return mSize == 0;
		}
	private:
		Node* mTop;
		size_t mSize;
	};
}