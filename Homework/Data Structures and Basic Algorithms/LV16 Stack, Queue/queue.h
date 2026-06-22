#pragma once

namespace Homework
{
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
		struct iterator
		{
		public:
			iterator(Node* node): p(node){}
			bool operator!=(const iterator& other) const
			{
				return (p != other.p);
			}
			iterator& operator++()
			{
				p = p->next;
				return *this;
			}
			T& operator*()
			{
				return p->data;
			}

			Node* p;
		};

	public:
		queue() :mHead(), mTail(), mSize(){}
		~queue()
		{
			clear();
		}

		void push(T data)
		{
			mSize++;
			if (mHead == nullptr)
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
			if (!mHead)
				return;

			mSize--;

			Node* deleteNode = mHead;
			mHead = mHead->next;

			delete deleteNode;
			deleteNode = nullptr;
		}

		void pop_back()
		{
			if (!mHead)
				return;

			mSize--;

			Node* deleteNode = mHead;
			while (deleteNode->next != mTail)
				deleteNode = deleteNode->next;

			mTail = deleteNode;
			mTail->next = nullptr;

			deleteNode = deleteNode->next;
			delete deleteNode;
			deleteNode = nullptr;
		}

		void clear()
		{
			while (mSize != 0)
				pop();
		}

		T find(T data)
		{
			Node* cur = mHead;
			T findData = -1;
			for (int i = 0; i < mSize; ++i)
			{
				if (cur->data == data)
				{
					findData = cur->data;
					break;
				}
				cur = cur->next;
			}

			return findData;
		}
		
		bool empty()
		{
			return mSize == 0;
		}

		T front()
		{
			return mHead->data;
		}

		size_t size()
		{
			return mSize;
		}
		iterator begin()
		{
			return iterator(mHead);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

	private:
		Node* mHead;
		Node* mTail;
		size_t mSize;

	};
}