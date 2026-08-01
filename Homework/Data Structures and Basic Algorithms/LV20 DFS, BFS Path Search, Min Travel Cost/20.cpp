#include <iostream>
using namespace std;

const int len = 3;
string names[len]{};
string ret[len]{};

void Print()
{
	for (int i = 0; i < len; ++i)
		cout << ret[i] << " ";
	cout << endl;
}

void DFS(int level)
{
	if (level == len)
	{
		Print();
		return;
	}

	for (int i = 0; i < len; ++i)
	{
		ret[level] = names[i];
		DFS(level + 1);
		ret[level] = "\0";
	}
}

int main()
{
	for (int i = 0; i < len; ++i)
		cin >> names[i];

	DFS(0);
}