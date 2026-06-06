#include <iostream>
using namespace std;

struct Node
{
	int win;
	char name[256];

};

bool CheckName(const char* src, const char* dst)
{
	int idx{};
	while (src[idx] != '\0' && dst[idx] != '\0')
	{
		if (src[idx] != dst[idx])
			return false;

		idx++;
	}

	return true;
}

int FindFirstLove(const Node* train, const char* name, const int* age)
{
	for (int i = 0; i < 7; ++i)
	{
		if (train[i].win == *age)
		{
			if (CheckName(train[i].name, name))
				return i;
		}
	}

	return -1;
}

int main()
{
	Node train[7]
	{
		Node(15, "summer"),
		Node(33, "cioe"),
		Node(24, "summer"),
		Node(28, "niki"),
		Node(32,"jenny"),
		Node(20,"summer"),
		Node(40,"coco"),
	};

	char name[256]{};
	int age{};

	cin >> name >> age;

	int idx = FindFirstLove(train, name, &age);
	if (idx != -1)
		cout << idx;
	else
		cout << "없음";
}