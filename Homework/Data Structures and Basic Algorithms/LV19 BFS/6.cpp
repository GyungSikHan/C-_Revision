#include <iostream>
using namespace std;

const int length = 10;
int matrix[length][length]{};
string str{};

void MakeTree()
{
	int size = str.size();
	for (int i = 1; i <= str.size(); ++i)
	{
		if (i*2 <= size)
			matrix[i][i * 2] = 1;
		if (i*2+1 <= size)
			matrix[i][i * 2 + 1] = 1;
	}
}

void DFS(string& ret, int idx)
{
	if (idx > str.size())
		return;

	ret += str[idx-1];
	DFS(ret, idx * 2);
	DFS(ret, idx * 2+1);
}

int main()
{
	cin >> str;
	MakeTree();

	string ret;
	DFS(ret, 1);
	cout << ret;
}