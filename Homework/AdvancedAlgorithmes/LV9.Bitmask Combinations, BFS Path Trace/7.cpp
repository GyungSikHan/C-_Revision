#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int A;
	int B;
	int count{};
	int index{};
};

const int length = 5;
const int MaxCount = 12;
const pair<int, int> dx[4]{{-1,-1},{-1,1},{1,-1},{1,1}};
const int gest[MaxCount]{ 0,1,0,1,0,1,2,3,2,3,2,3 };

int doors[length]{};

Node node;
int A;
int B;

void Print(const int a, const int b, const int count)
{
	int visited[length]{};
	visited[a] = 1;
	visited[b] = 1;
	cout << endl << endl;
	cout << count << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << visited[i] << " ";
	}
}

void bfs()
{
	int visited[length]{};
	visited[node.A] = 1;
	visited[node.B] = 1;

	queue<Node> qu;
	qu.push(node);

	auto verdict = [&](const int& a, const int& b)
		{
			if ((a < 0 || a >= length || b < 0 || b>=length) || a >= b)
				return false;
			return true;
		};

	while (!qu.empty())
	{
		int idx = qu.front().index;
		
		if (idx == MaxCount)
			break;
		int count = qu.front().count;
		int a = qu.front().A;
		int b = qu.front().B;
		//Print(a, b,idx);
		if (a != gest[idx] && b != gest[idx])
		{
			qu.front().index++;
			continue;
		}
		qu.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextA = dx[i].first + a;
			int nextB = dx[i].second + b;
			if (!verdict(nextA, nextB))
				continue;

			qu.push({ nextA,nextB, count+2,idx});
		}
	}

	cout << qu.front().count;
}

int main()
{
	int cnt{};
	for (int i = 0; i < length; ++i)
	{
		cin >> doors[i];
		if (doors[i] == 1)
		{
			if (cnt == 0)
				A = i;
			else
				B = i;
			cnt++;
		}
	}

	node.A = A;
	node.B = B;

	bfs();
}