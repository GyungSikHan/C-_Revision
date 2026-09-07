#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>


struct Node
{
	int data;
	char c1;
	char c2;
};

auto Compare = [](const Node& a, const Node& b)
	{
		return a.data < b.data;
	};
std::priority_queue<Node, std::vector<Node>, decltype(Compare)> qu;
int n{};
std::vector<std::vector<int>> v;

void InputNode()
{
	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; ++i)
			qu.push({ v[j][i], (char)(j + 'A'), (char)(i + 'A')});
}

void PrintThreeData()
{
	for (int i = 0; i < 3; ++i)
	{
		std::cout << qu.top().c1 << "-" << qu.top().c2 << " " << qu.top().data << std::endl;
		qu.pop();
	}
}

int main()
{
	std::cin >> n;
	v.assign(n, std::vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> v[i][j];

	InputNode();
	PrintThreeData();
}