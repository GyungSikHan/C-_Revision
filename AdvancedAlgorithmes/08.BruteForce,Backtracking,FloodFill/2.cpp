#include <Windows.h>
#include <iostream>

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

void printMap()
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

void FloodFill(int x, int y)
{
	if (map[y][x] == '.')
	{
		map[y][x] = '@';
		Sleep(1000);
		system("cls");

		printMap();

		FloodFill(x, y + 1);
		FloodFill(x-1, y);
		FloodFill(x, y-1);
		FloodFill(x+1, y);
	}
}

int main()
{
	printMap();

	std::cout << "==================================" << std::endl;
	FloodFill(4,3);

}

