#pragma once
#include <iterator>
namespace ya3
{
	template <typename T>
	class list
	{
	private:
		struct Node
		{
			Node* next;
			T data;
		public:
			Node() :next(), data() {}
		};

	public:
		struct iterator
		{
		public:
			iterator(Node* node) :p(node) {}
			T operator*() const
			{
				return p->data;
			}
			iterator& operator+(int index)
			{
				while (index != 0)
				{
					p = p->next;
					index--;
				}
				return *this;
			}
			iterator& operator++()
			{
				p = p->next;
				return *this;
			}
			bool operator!=(const iterator& iter)const
			{
				return p != iter.p;
			}
			bool operator==(const iterator& iter) const
			{
				return p == iter.p;
			}
		public:
			Node* p;
		};

	public:
		list() :head(), tail(), listSize() {}
		~list()
		{
			clear();
		}

		void push_back(T data)
		{
			listSize++;

			if (!head)
			{
				head = new Node();
				head->data = data;
				head->next = nullptr;
				tail = head;
				return;
			}

			tail->next = new Node();
			tail->next->data = data;
			tail->next->next = nullptr;
			tail = tail->next;
		}
		void push_front(T data)
		{
			listSize++;
			if (!head)
			{
				head = new Node();
				head->data = data;
				head->next = nullptr;
				tail = head;
				return;
			}

			Node* temp = new Node();
			temp->data = data;
			temp->next = head;
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
				temp = temp->next;

			delete tail;
			tail = nullptr;
			tail = temp;
			tail->next = nullptr;
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
		T front()
		{
			return head->data;
		}
		T back()
		{
			return tail->data;
		}

		bool empty()
		{
			return listSize == 0;
		}
		int size()
		{
			return listSize;
		}
		void clear()
		{
			while (listSize != 0)
			{
				pop_front();
			}
		}

		void insert(iterator pos, T data)
		{
			listSize++;
			if (pos.p == nullptr)
			{
				pos.p = new Node();
				pos.p->data = data;
				pos.p->next = nullptr;
				return;
			}
			Node* temp = head;
			bool bFlag{};
			
			while (temp->next != tail)
			{
				if (temp == pos.p)
				{
					bFlag = true;
					break;
				}
				temp = temp->next;
			}
			
			if (!bFlag)
				return;

			Node* temp2 = new Node();
			temp2->data = data;
			temp2->next = temp->next;
			temp->next = temp2;
		}
		iterator erase(iterator& pos)
		{
			if (pos.p == nullptr)
				return nullptr;
			listSize--;
			Node* temp = head;
			while (temp->next != pos.p)
				temp = temp->next;
			temp->next = pos.p->next;

			delete pos.p;
			pos.p = nullptr;
			return temp->next;
		}

		iterator begin()
		{
			return iterator(head);
		}
		iterator end()
		{
			return iterator(nullptr);
		}

		void remove(T data)
		{
			if (head == nullptr)
				return;

			bool bFlag{};
			Node* temp = head;
			while (temp != tail)
			{
				if (temp->next->data == data)
				{
					bFlag = true;
					break;
				}
				temp = temp->next;

			}

			if (bFlag == false)
				return;
			listSize--;
			Node* deleteNode = temp->next;
			Node* nextNode = deleteNode->next;
			temp->next = nextNode;

			delete deleteNode;
			deleteNode = nullptr;
		}

		iterator find(T data)
		{
			if (head == nullptr)
				return end();

			iterator temp = begin();
			while (temp != nullptr)
			{
				if (temp.p->data == data)
					return temp;

				temp = temp.p->next;
			}


			return end();
		}

	private:
		Node* head;
		Node* tail;
		int listSize;
	}; }
