#include <iostream>
#include <vector>
using namespace std;

struct Point
{
	int y;
	int x;
};
const Point Direction[4]
{
	{0,1},
	{1,0},
	{0,-1}, 
	{-1,0}
};

char map[4][3]{};
vector<Point> MonsterPos;

void Move(int idx)
{
	Point direction = Direction[idx];

	for (int i = 0; i < MonsterPos.size(); ++i)
	{
		Point next = {MonsterPos[i].y+direction.y, MonsterPos[i].x+direction.x};

		if (next.y < 0 || next.y >= 4 || next.x < 0 || next.x >= 3)
			continue;
		if (map[next.y][next.x] != '_')
			continue;

		char c = map[MonsterPos[i].y][MonsterPos[i].x];
		map[MonsterPos[i].y][MonsterPos[i].x] = '_';
		map[next.y][next.x] = c;

		MonsterPos[i].y = next.y;
		MonsterPos[i].x = next.x;
	}
}

void Print()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << map[i][j];
		}	
		cout << endl;
	}
}

int main()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] >= 'A' && map[i][j] <= 'Z')
				MonsterPos.push_back({ i,j });
		}
	}

	int idx{};
	for (int i = 0; i < 5; ++i)
	{
		if (idx == 4)
			idx = 0;
		Move(idx);
		idx++;
	}
	Print();
}