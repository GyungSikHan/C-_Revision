#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	char c;
};

Node* head = new Node;



void BFS(const string& str)
{
	queue<int> qu;
	vector<int> depth(str.size()+1, -1);

	qu.push(1);
	depth[0] = 0;
	depth[1] = 1;

	while(!qu.empty())
	{
		int curr = qu.front();
		qu.pop();
		
		for (int next : {curr*2, curr*2+1})
		{
			if (next > str.size())
				break;
			depth[next] = depth[curr]+1;
			qu.push(next);
		}
	}


	for (int i = 1; i < depth.size(); ++i)
	{
		Node* node = head;
		if (i == 1)
			node->c = str[i - 1];
		else
		{
			for (int j = 1; j < depth[i]; ++j)
			{
				
			}
		}
	}
}

int main()
{
	string str{};
	cin >> str;

	BFS(str);
}