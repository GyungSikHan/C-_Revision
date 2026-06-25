#include <iostream>
using namespace std;

int main()
{
	int map[5][5]
	{
		0,1,7,2,0,
		1,0,8,0,5,
		7,8,0,3,6,
		2,0,3,0,0,
		0,5,6,0,0
	};

	for (int i = 0; i < 5; ++i)
		for (int j = i+1; j < 5; ++j)
			if (map[i][j] != 0)
				cout << (char)('A' + i) << " " << (char)('A' + j) << " " << map[i][j] << endl;
}