#include <iostream>
using namespace std;

int main()
{
	int vec[3][3]
	{
		3,4,1,
		5,5,7,
		8,3,2
	};

	int min = vec[0][0];
	int y{}, x{};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (vec[i][j] < min)
			{
				min = vec[i][j];
				y = i;
				x = j;
			}
		}
	}

	cout << y << " " << x << endl;
	cout << min << endl;
}