#pragma once

namespace ya2
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
		struct iterator
		{
		public:
			Node* p;

			iterator(Node* node):p(node){}
			bool operator!=(const iterator& other)const
			{
				return p != other.p;
			}
			iterator operator++()
			{
				p = p->next;
				return *this;
			}
			T operator*()
			{
				return p->data;
			}
		};

	public:
		list():head(), tail(), listSize(){}
		~list()
		{
			clear();
		}
		void MakeHead(T data)
		{
			head = new Node();
			head->data = data;
			head->next = nullptr;
			tail = head;
		}
		void push_front(T data)
		{
			listSize++;
			if (!head)
			{
				MakeHead(data);
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
				MakeHead(data);
				return;
			}

			tail->next = new Node();
			tail->next->data = data;
			tail->next->next = nullptr;
			tail = tail->next;
		}
		void pop_front()
		{
			if (!head)
				return;
			listSize--;
			if (head == tail)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
				return;
			}

			Node* temp = head->next;
			delete head;
			head = nullptr;
			head = temp;
		}
		void pop_back()
		{
			if (!head)
				return;
			listSize--;
			if (head == tail)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
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
		}

		void clear()
		{
			while (listSize != 0)
			{
				pop_front();
			}
		}
		int size()
		{
			return listSize;
		}
		bool empty()
		{
			return listSize == 0;
		}
		iterator begin()
		{
			return iterator(head);
		}
		iterator end()
		{
			return iterator(nullptr);
		}
	private:
		Node* head;
		Node* tail;
		int listSize;
	};
}