#pragma once
template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T value;
		Node* next;
	};

public:
	struct iterator
	{
	public:
		iterator(Node* node) : p(node) {}
		bool operator!=(const iterator& other) const
		{
			return p != other.p;
		}
		iterator& operator++()
		{
			p = p->next;
			return *this;
		}
		T& operator*()
		{
			return p->value;
		}

	public:
		Node* p;
	};

public:
	LinkedList() :head(), tail(), size() {}
	template <typename... Args>
	LinkedList(Args... args)
		: head(), tail()
	{
		(push_back(args), ...);
	}
	LinkedList(const LinkedList<T>& other)
	{
		Node* node = other.head;
		for (int i = 0; i < other.size; ++i)
		{
			push_back(node->value);
			node = node->next;
		}
	}
	~LinkedList()
	{
		if (head != nullptr)
			clear();
	}
	void push_back(T value)
	{
		size++;
		if (!head)
		{
			head = new Node();
			head->value = value;
			head->next = nullptr;
			tail = head;

			return;
		}

		tail->next = new Node();
		tail->next->value = value;
		tail->next->next = nullptr;
		tail = tail->next;
	}
	void clear()
	{
		Node* cur = head;
		for (int i = 0; i<size; i++)
		{
			head = cur->next;
			delete cur;
			cur = nullptr;
			cur = head;
		}

		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void remove(T value)
	{
		if (head == nullptr)
			return;

		Node* cur = head;
		if (head->value == value)
		{
			size--;
			head = cur->next;
			delete cur;
			cur = nullptr;
			return;
		}
		bool bFlag{};
		Node* prev{};
		while (cur->next != nullptr)
		{
			if (cur->value == value)
			{
				bFlag = true;
				break;
			}
			prev = cur;
			cur = cur->next;
		}
		if (!bFlag)
			return;
		size--;
		prev->next = cur->next;
		delete cur;
		cur = nullptr;
	}
	void ReverseRemove(int index)
	{
		if (head == nullptr)
			return; 
		if (head == tail)
		{
			if (index == 1)
			{
				size--;
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			return;
		}

		int removeIndex = (size - index);
		int cnt{};
		Node* cur = head;
		bool bFlag{};
		Node* prev{};
		while (cur->next != nullptr)
		{
			if (removeIndex == cnt)
			{
				bFlag = true;
				break;
			}
			prev = cur;
			cur = cur->next;
			cnt++;
		}

		if (removeIndex == cnt)
			bFlag = true;

		if (!bFlag)
			return;

		prev->next = cur->next;
		size--;
		delete cur;
	}	

	void reverse()
	{
		if (size == 0 || size == 1)
			return;

		int cnt{};
		Node* halfNode = head;
		while (cnt != size/2)
		{
			cnt++;
			halfNode = halfNode->next;
		}
		
		Node* left = head;
		int tempSize = size;
		for (int i = 0; i < size/2; ++i)
		{
			int cnt = size/2;
			Node* right = halfNode;
			while (cnt != tempSize-1)
			{
				right = right->next;
				cnt++;
			}

			tempSize--;
			T temp = left->value;
			left->value = right->value;
			right->value = temp;
			left = left->next;
		}
	}

	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(nullptr);
	}

	LinkedList operator+(const LinkedList<T>& other) const
	{
		LinkedList<T> ret;

		Node* cur = head;
		while (cur)
		{
			ret.push_back(cur->value);
			cur = cur->next;
		}

		cur = other.head;
		while (cur)
		{
			ret.push_back(cur->value);
			cur = cur->next;
		}

		return ret;
	}

	void sort()
	{
		if (size == 0)
			return;

		for (int i = 0; i < size-1; ++i)
		{
			Node* temp = head;
			for (int j = 0; j < i; ++j)
				temp = temp->next;
			int value = temp->value;
			int j = i - 1;
			while (j >= 0)
			{
				Node* prev = head;
				for (int k = j; k > 0; k--)
					prev = prev->next;
				j--;
				if (value < prev->value)
				{
					prev->next->value = prev->value;
					temp = prev;
				}
				else
					break;
			}
			temp->value = value;

		}
	}

	bool operator==(const LinkedList<T>& other) const
	{
		if (size != other.size)
			return false;

		Node* thisNode = head;
		Node* otherNode = other.head;
		int len{};
		for (int i = 0; i < size; ++i)
		{
			if (thisNode->value != otherNode->value)
				return false;

			thisNode = thisNode->next;
			otherNode = otherNode->next;
			len++;
		}

		return true;
	}

	bool Cycle(int index)
	{
		if (index < 0 || size-1 <= index)
			return false;

		Node* node = head;
		for (int i = 0; i < index; ++i)
			node = node->next;

		tail->next = node;
		return true;
	}
private:
	Node* head;
	Node* tail;
	size_t size;
};
