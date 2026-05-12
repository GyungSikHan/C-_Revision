#include <iostream>
using namespace std;

struct Point
{
	int y;
	int x;
};

int dir[8][2]
{
	-1,0,
	-1,1,
	0,1,
	1,1,
	1,0,
	1,-1,
	0,-1,
	-1,-1
};

char map[4][5]
{
	'-','-','-','-','-',
	'-','-','-','-','-',
	'-','-','-','-','-',
	'-','-','-','-','-'
};

void Boom(const Point& point)
{
	for (int i = 0; i < 8; ++i)
	{
		int ny = point.y + dir[i][0];
		int nx = point.x + dir[i][1];

		if (nx < 0 || nx>=5 || ny < 0 || ny>=4 || map[ny][nx] != '-')
			continue;

		map[ny][nx] = '#';
	}
}

int main()
{

	Point points[2];
	for (int i = 0; i < 2; ++i)
	{
		cin >> points[i].y >> points[i].x;
	}

	for (int i = 0; i < 2; ++i)
	{
		Boom(points[i]);
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout << map[i][j];
		}
		cout << endl;
	}

}