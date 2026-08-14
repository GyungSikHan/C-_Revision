#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};
vector<int> v{ 7,3,8,10,1,5 };
Node* tree;

void DFS(int level)
{
	if (level == v.size())
		return;

	Node* curr = tree;
	bool b{};
	while (true)
	{
		if (curr->data < v[level])
		{
			if (curr->right == nullptr)
			{
				b = false;
				break;
			}
			curr = curr->right;
		}
		else
		{
			if (curr->left == nullptr)
			{
				b = true;
				break;
			}
			curr = curr->left;
		}
	}

	if (b == false)
	{
		curr->right = new Node;
		curr = curr->right;
	}
	else
	{
		curr->left = new Node;
		curr = curr->left;
	}

	curr->data = v[level];
	curr->left = nullptr;
	curr->right = nullptr;

	DFS(level + 1);
}

int Serch(int val)
{
	int idx{};
	Node* curr = tree;
	while (curr != nullptr)
	{
		if (curr->data < val)
			curr = curr->right;
		else if (curr->data > val)
			curr = curr->left;
		else
			return idx;
		idx++;
	}

	return -1;
}

int main()
{
	tree = new Node;
	tree->data = v[0];
	tree->left = nullptr;
	tree->right = nullptr;

	DFS(1);

	int idx = Serch(20);
	if (idx != -1)
		cout << idx << "번째" << endl;
	else
		cout << "없음" << endl;
}