#include <algorithm>
#include <iostream>
using namespace std;

int map[4][5]{};

struct Point
{
	int y;
	int x;
};
Point point[20]{};
int length{};

bool compare(Point a, Point b)
{
	if (a.x == b.x)
		return a.y < b.y;

	return a.x < b.x;
}

int main()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 5; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				point[length].y = i;
				point[length].x = j;
				length++;
			}
		}
	

	sort(&(point[0]), &(point[length - 1]), compare);
	
	cout << "(" << point[0].y<< "," << point[0].x<< ")" << endl;
	cout << "(" << point[length-1].y<< "," << point[length-1].x << ")" << endl;
}