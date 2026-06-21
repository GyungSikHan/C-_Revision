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

		void OddEvenLinkedList()
		{
			if (!head)
				return;

			for (int i = 1; i < length; ++i)
			{
				Node* key = head;
				int keyData{};
				
				for (int j = 0; j < i; j++)
					key = key->next;
				keyData = key->data;
				
				int j = i - 1;
				while (j >= 0)
				{
					Node* temp = head;
					if (j != 0)
					{
						for (int k = j; k > 0; k--)
							temp = temp->next;
					}
					j--;
					if (keyData % 2 == 1)
					{
						if (temp->data % 2 == 0)
						{
							key->data = temp->data;
							key = temp;
						}
						else
						{
							if (temp->data > keyData)
							{
								key->data = temp->data;
								key = temp;
							}
							else
								break;
						}
					}
					else
					{
						if (temp->data % 2 == 1)
							break;
						else
						{
							if (temp->data > keyData)
							{
								key->data = temp->data;
								key = temp;
							}
							else
								break;
						}
					}
				}

				key->data = keyData;
			}
		}

		iterator SerchNode(int value)
		{
			Node* cur = head;
			while (cur->next != nullptr)
			{
				if (cur->data == value)
					break;
				
				cur = cur->next;
			}

			return cur;
		}

		void IntersectVal(iterator node)
		{
			tail->next = node.p;
		}

	private:
		Node* head;
		Node* tail;
		size_t length;
	};
}