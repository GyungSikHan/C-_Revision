#include <iostream>
using namespace std;

int main()
{
	int vect[4][3]{};
	int input[4][2]{};

	for (int i = 0; i < 4; ++i)
	{
		cin >> input[i][0] >> input[i][1];
	}

	for (int i = 0; i < 4; ++i)
	{
		vect[input[i][0]][input[i][1]] = 5;
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << vect[i][j] << " ";
		}
		cout << endl;
	}
}