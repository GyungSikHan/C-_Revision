#include <iostream>
#include <vector>

using namespace std;
const int length = 30;

int Q[length];
int level[length];
int parent[length];
int head = 0;
int tail = 2;

void Print(int idx)
{
	while (true)
	{
		if (idx == -1)
			break;

		cout << Q[idx] << " ";
		idx = parent[idx];
	}
}

int main()
{
	for (int i = 0; i < 2; ++i)
	{
		Q[i] = i + 1;
		level[i] = 1;
		parent[i] = -1;
	}	

	while (true)
	{
		for (int i = 0; i < 2; ++i)
		{
			Q[tail] = i + 1;
			level[tail] = level[head] + 1;
			parent[tail] = head;
			tail++;
		}

		head++;

		if (level[head] == 3)
			break;
	}

	for (int i = head; i < tail; ++i)
	{
		cout << endl;
		Print(i);
	}
}