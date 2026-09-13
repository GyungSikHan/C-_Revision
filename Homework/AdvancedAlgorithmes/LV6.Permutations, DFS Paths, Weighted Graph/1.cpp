#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool visited[4]{};
int card[4]{ 1,3,4,6 };

void DFS(string str, int level)
{
	if (level == 4)
	{
		cout << str << endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (visited[i] == true)
			continue;

		visited[i] = true;
		DFS(str + std::to_string(card[i]), level + 1);
		visited[i] = false;
	}
}

int main()
{
	DFS("", 0);
}