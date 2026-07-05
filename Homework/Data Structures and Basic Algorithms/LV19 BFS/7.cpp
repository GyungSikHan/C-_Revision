#include <iostream>
#include <queue>
using namespace std;

const int length = 8;
int arr[length]{};

void BFS()
{
	queue<int>qu;
	int idx{};
	while (arr[idx] == 0)
		idx++;
	qu.push(idx);

	while (!qu.empty())
	{
		int curr = qu.front();
		qu.pop();
		cout << arr[curr] << " ";

		for (int i = curr+1; i < length; ++i)
		{
			if (arr[i] == 0)
				continue;

			qu.push(i);
			break;
		}
	}
}

int main()
{
	for (int i = 0; i < length; ++i)
		cin >> arr[i];
	BFS();
}