#include <iostream>
using namespace std;

int main()
{
	bool mask1[4][4]
	{
		0,0,0,1,
		1,1,0,1,
		1,0,0,1,
		1,1,1,1
	};
	bool mask2[4][4]
	{
		1,1,1,1,
		1,0,1,1,
		1,0,0,0,
		1,0,0,0
	};
	bool ret[4][4]{};

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if ((mask1[i][j] | mask2[i][j]) == 1)
				ret[i][j] = true;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (ret[i][j] == 0)
			{
				cout << "(" << i << "," << j << ")" << endl;
			}

		}
	}
}