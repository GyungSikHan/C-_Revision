#include <iostream>
using namespace std;

const int lenght = 5;
int map[lenght]{};

void Print(int life)
{
	for (int i = 0; i < lenght; ++i)
	{
		if (map[i] == 0)
			cout << "_";
		else
			cout << life;
	}
	cout << endl;
}
void Move(int index, int life)
{
	if (life == 0 || index >= lenght)
	{
		Print(life);
		return;
	}

	Print(life);
	map[index] = 0;
	map[index + 1] = life - 1;
	Move(index + 1, life - 1);
}


int main()
{
	int indxe{};
	int life{};

	cin >> indxe >> life;

	map[indxe] = life;
	Move(indxe, life);
}