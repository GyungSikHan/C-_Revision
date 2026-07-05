#include <iostream>
#include <queue>
using namespace std;

const int length = 10;
int matrix[length][length]
{
	0,1,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,0,0,0,
	0,0,0,0,0,0,0,1,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,1,0,
	0,0,0,0,0,0,0,0,0,1,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0
};

void BFS(const char c)
{
	queue<int> qu;
	qu.push(c - 'A');

	while (!qu.empty())
	{
		int curr = qu.front();
		qu.pop();
		cout << (char)(curr + 'A')<<" ";
		for (int i = 0; i < length; ++i)
		{
			if (matrix[curr][i] == 1)
				qu.push(i);
		}
	}
}

int main()
{
	char c{};
	cin >> c;

	BFS(c);
}