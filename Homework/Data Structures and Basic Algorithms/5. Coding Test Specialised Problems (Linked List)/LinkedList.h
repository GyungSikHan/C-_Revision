#pragma once
namespace ya
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
			iterator(Node* node) :p(node) {}
			T operator*() const
			{
				return p->data;
			}
			bool operator!=(const iterator& other) const
			{
				return (p != other.p);
			}
			iterator& operator++()
			{
				p = p->next;
				return *this;
			}
		public:
			Node* p;
		};

	public:
		list() :head(), tail(), length() {}
		void push_back(T data)
		{
			length++;
			if (!head)
			{
				head = new Node();
				head->data = data;
				tail = head;
				return;
			}

			tail->next = new Node();
			tail->next->data = data;
			tail->next->next = nullptr;
			tail = tail->next;
		}
		const size_t size() const
		{
			return length;
		}

		T& find(size_t index) const
		{
			Node* temp = head;
			while (temp != tail)
			{
				if (index == 0)
					break;
				temp = temp->next;
				index--;
			}
			return temp->data;
		}

		iterator begin() const
		{
			return iterator(head);
		}
		iterator end() const
		{
			return nullptr;
		}
		bool operator!=(const iterator& other)
		{
			return (this != other.p);
		}

	private:
		Node* head;
		Node* tail;
		size_t length;
	};
}