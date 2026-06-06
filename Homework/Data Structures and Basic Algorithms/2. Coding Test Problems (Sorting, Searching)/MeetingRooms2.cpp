#include <iostream>
using namespace std;

struct Node
{
	int s;
	int e;
};

int main()
{
	int n{};
	Node node[5000]{};

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin >> node[i].s >> node[i].e;
	}

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 1; i < n; ++i)
	{
		Node temp = node[i];
		int idx = i;
		for (int j = i-1; j >= 0; j--)
		{
			if(temp.s < node[j].s)
			{
				node[idx] = node[j];
				idx = j;
			}
			else
				break;
		}
		node[idx] = temp;
	}

	bool visited[5001]{};
	int cnt{};
	for (size_t i = 0; i < n - 1; i++)
	{
		if(visited[i])
			continue;

		visited[i] = true;
		cnt++;
		for (int j = i+1; j < n; j++)
		{
			if(node[i].e < node[j].s)
			{
				node[i].e = node[j].e;
				visited[j] = true;
			}
		}
	}
	
	cout<<cnt;
}