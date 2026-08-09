#include <iostream>
#include <vector>
using namespace std;

int index{};

struct Moving
{
	int cnt;
	int direction;
};

Moving moves[7]
{
	Moving(3,1),
	Moving(2, 1),
	Moving(1, -1),
	Moving(3, 1),
	Moving(2, -1),
	Moving(-1, 0),
	Moving(1, -1),
};
vector<int> v;

void DFS(int idx)
{
	if (moves[idx].direction == 0)
	{
		v.push_back(idx);
		for (auto i = v.rbegin(); i != v.rend(); ++i)
			cout << *i << "번" << endl;
		
		return;
	}

	v.push_back(idx);
	if (moves[idx].direction == 1)
	{
		DFS(idx + moves[idx].cnt);
	}
	else if (moves[idx].direction == -1)
	{
		DFS(idx - moves[idx].cnt);
	}
}

int main()
{
	cin >> index;
	DFS(index); 
}