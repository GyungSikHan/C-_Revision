#include <iostream>
using namespace std;

int map[3][3]{};

bool Check(int* arr)
{
	for (int i = 0; i < 2; ++i)
		if (arr[i] != arr[i + 1])
			return false;
	return true;
}

int main()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> map[i][j];

	for (int i = 0; i < 3; ++i)
	{
		if (Check(map[i]))
			cout << map[i][0] << endl;
		else
			cout << "x" << endl;
	}
}