#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Tree
{
	int data;
	Tree* left;
	Tree* right;
};

class Codec
{
public:
	string serialize(Tree* root)
	{
		if (root == nullptr)
			return "";

		int idx = 0;
		bool bFirst = true;
		string ret{};
		queue<Tree*>qu;
		qu.push(root);

		while (!qu.empty())
		{
			if (idx >= size)
				break;
			idx++;
			Tree* curr = qu.front();
			qu.pop();
			if (bFirst == false)
				ret += ",";
			bFirst = false;
			if (curr == nullptr)
			{
				ret += "null";
				continue;
			}

			ret += to_string(curr->data);
			qu.push(curr->left);
			qu.push(curr->right);
		}

		return ret;
	}
	Tree* deserialize(string str)
	{
		if (str.empty())
			return nullptr;

		StringSplit(str);

		Tree* tree = new Tree;
		tree->data = stoi(v[0]);
		tree->left = nullptr;
		tree->right = nullptr;

		BFS(tree);

		return tree;
	}

private:
	void StringSplit(string str)
	{
		if (str.empty())
		{
			size = v.size();
			return;
		}

		auto iter = str.find(',');

		string temp = str;
		if (iter != str.npos)
		{
			str.erase(str.begin(), str.begin() + iter);
			if (str[0] == ',')
				str.erase(str.begin(), str.begin() + 1);
			temp.erase(iter);
		}
		else
		{
			str = "\0";
		}
		v.push_back(temp);

		StringSplit(str);
	}
	void BFS(Tree* tree)
	{
		queue<Tree*> qu;
		qu.push(tree);
		int idx = 1;

		while (!qu.empty())
		{
			if (idx >= size)
				break;
			Tree* curr = qu.front();
			qu.pop();
			int size = idx + 2;
			for (idx; idx < size; ++idx)
			{
				if (v[idx] == "null")
					continue;
				Tree* temp{};
				if (idx % 2 == 1)
				{
					curr->left = new Tree{};
					temp = curr->left;
				}
				else
				{
					curr->right = new Tree{};
					temp = curr->right;
				}

				temp->data = stoi(v[idx]);
				temp->left = nullptr;
				temp->right = nullptr;
				qu.push(temp);
			}
		}
	}


private:
	vector<string> v;
	int size;
};

int main()
{
	string root = "1,2,3,null,null,4,5";
	Codec codec{};

	Tree* tree = codec.deserialize(root);
	string str = codec.serialize(tree);

	cout << str;
}