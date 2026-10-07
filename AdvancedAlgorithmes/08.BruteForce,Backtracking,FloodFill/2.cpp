#include <iostream>

using namespace std;

char map[9][10] =
{
	"#########",
	"#...#...#",
	"#...#...#",
	"#..#....#",
	"###...###",
	"#....#..#",
	"#...#...#",
	"#...#...#",
	"#########"
};

void PrintMap()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

void FloodFill(int y, int x)
{
	if (map[y][x] == '.')
	{
		map[y][x] = '@';

		FloodFill(y + 1, x);
		FloodFill(y-1, x);
		FloodFill(y, x+1);
		FloodFill(y, x-1);
	}
}
int main()
{
	PrintMap();
	std::cout << "==========================" << std::endl;
	FloodFill(4, 4);
	PrintMap();

}