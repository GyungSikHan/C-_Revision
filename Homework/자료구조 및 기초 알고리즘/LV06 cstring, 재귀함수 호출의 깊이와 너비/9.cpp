#include <iostream>
using namespace std;

int main()
{
	char map[4][3]{};
	int y{}, x{};
	int y2{}, x2{};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == 'A')
			{
				y = i;
				x = j;
			}
			else if (map[i][j] == 'B')
			{
				y2 = i;
				x2 = j;
			}
		}
	}

	cout<<std::abs(y - y2) + std::abs(x - x2);
}