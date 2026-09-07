#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct Node
{
	int value;
	int level;
	int parent;
};

int main()
{
	Node nodes[30]{};
	int nodeCount{};

	queue<int>q;

	nodes[nodeCount] = {1,1,-1};
	q.push(nodeCount);
	nodeCount++;

	nodes[nodeCount] = {2,1,-1};
	q.push(nodeCount);
	nodeCount++;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (nodes[current].level == 3)
			continue;

		for (int i = 1; i <= 2; ++i)
		{
			nodes[nodeCount].value = i;
			nodes[nodeCount].level = nodes[current].level + 1;
			nodes[nodeCount].parent = current;

			q.push(nodeCount);
			nodeCount++;
		}
	}

	cout << "===== 생성된 노드 =====\n";
	for (int i = 0; i < nodeCount; ++i)
	{
		cout << "Index : " << i << " Value : " << nodes[i].value << 
			" Level : " << nodes[i].level << " Parent : " << nodes[i].parent << endl;
	}

	int target = 13;
	cout << "\nTarget Index : " << target << endl;

	stack<int> path;

	while (target != -1)
	{
		path.push(nodes[target].value);
		target = nodes[target].parent;
	}

	cout << "Path : ";

	while (!path.empty())
	{
		cout << path.top() << " ";
		path.pop();
	}
	cout << endl;
}