#pragma once

namespace ya
{
	template <typename T>
	class list
	{
	private:
		struct Node
		{
			T data{};
			Node* next{};
		};
	public:
		list() :head(), tail(), listSize() {}
		~list()
		{
			clear();
		}

		void HeadPush(T data)
		{
			head = new Node();
			head->data = data;
			tail = head;
			tail->next = nullptr;
		}

		void push_front(T data)
		{
			listSize++;
			if (!head)
			{
				HeadPush(data);
				return;
			}

			Node* temp = new Node();
			temp->data = data;
			temp->next = head;

			head = temp;
		}
		void push_back(T data)
		{
			listSize++;
			if (!head)
			{
				HeadPush(data);
			}
			else
			{
				tail->next = new Node();
				tail->next->data = data;
				tail = tail->next;
				tail->next = nullptr;
			}
		}
		int size()
		{
			return listSize;
		}

		void pop_back()
		{
			if (head == nullptr)
				return;
			if (head == tail)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
				listSize = 0;
				return;
			}

			Node* temp = head;

			while (temp->next != tail)
			{
				temp = temp->next;
			}
			delete tail;
			tail = nullptr;
			tail = temp;
			tail->next = nullptr;
			listSize--;
		}

		void pop_front()
		{
			if (!head)
				return;

			Node* temp = head->next;
			delete head;
			head = nullptr;
			head = temp;
			listSize--;

			if (head == nullptr)
				tail = nullptr;
		}

		Node* begin()
		{
			return head;
		}
		Node* end()
		{
			if (tail == nullptr)
				return nullptr;
			return tail->next;
		}

		void clear()
		{
			if (!head)
				return;

			Node* cur = head;
			while (cur != nullptr)
			{
				Node* next = cur->next;
				delete cur;
				cur = nullptr;
				cur = next;
			}

			head = nullptr;
			tail = nullptr;
			listSize = 0;
		}
	public:
		struct iterator
		{
			Node* p;
			iterator(Node* node):p(node){}
			bool operator != (const iterator& other) const
			{
				return (p != other.p);
			}
			iterator& operator++()
			{
				p = p->next;
				return *this;
			}
			T operator*()
			{
				return p->data;
			}
		};

	private:
		Node* head;
		Node* tail;
		int listSize;
	};
}
