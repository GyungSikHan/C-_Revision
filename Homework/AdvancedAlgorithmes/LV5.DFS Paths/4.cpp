#include <iostream>
using namespace std;

enum Animal
{
	Turtle,
	Mouse,
	Rabbit,
	Monkey,
	Dog,
	Cat
};

int a{}, b{};
int arr[6]{};
int cnt{};

void DFS(int level)
{
	if (arr[Animal::Dog] == a || arr[Animal::Dog] == b)
		return;
	if (level == 7)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < 6; ++i)
	{
		if (arr[i] != 0)
			continue;

		arr[i] = level;
		DFS(level + 1);
		arr[i] = 0;
	}
}

int main()
{
	cin >> a >> b;
	DFS(1);
	cout << cnt;
}