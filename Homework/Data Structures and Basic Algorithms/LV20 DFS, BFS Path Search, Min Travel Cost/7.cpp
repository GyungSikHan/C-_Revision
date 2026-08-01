#include <iostream>
using namespace std;

const int MAX = 10000;
char Ret[MAX];
int Input{};

void Print()
{
	for (int i = 0; i < Input; ++i)
		cout << Ret[i];
	cout << endl;
}
void DFS(int level)
{
	if (level == Input)
	{
		Print();
		return;
	}

	Ret[level] = 'O';
	DFS(level + 1);
	Ret[level] = 'X';
	DFS(level + 1);
}

int main()
{
	cin >> Input;
	DFS(0);

}