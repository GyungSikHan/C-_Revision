#include <iostream>
using namespace std;

char path[3];

void print(int win)
{
	if (win != 0)
		cout << win << "승(";
	else
		cout << "3패(";
	for (int i = 0; i < 3; ++i)
	{
		if (path[i] == 'O')
			cout << "승";
		else
			cout << "패";
	}
	cout << ")" << endl;
}

void Solve(int count, int win)
{
	if (count == 3)
	{
		print(win);
		return;
	}

	path[count] = 'O';
	Solve(count + 1, win + 1);
	path[count] = 'X';
	Solve(count + 1, win);
}

int main()
{
	Solve(0, 0);
}