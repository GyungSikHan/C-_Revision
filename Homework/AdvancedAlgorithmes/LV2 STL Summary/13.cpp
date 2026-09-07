#include <iostream>

using namespace std;

const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

char boungabbang[3][6]
{
	{'A','B','C','E','F','G'},
	{'H','I','J','K','L','M'},
	{'N','O','P','Q','R','S'},
};

bool visited[3][6];
string s{};

void Reverse(const int y, const int x)
{
	if (visited[y][x])
		return;

	static bool b{};
	static char temp[3][6]{};
	if (!b)
	{
		memcpy(temp, boungabbang, sizeof(boungabbang));
		b = true;
	}

	visited[y][x] = true;
	boungabbang[y][x] = '#';

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 3 || nx >= 6)
			continue;

		visited[y][x] = true;
		if (boungabbang[ny][nx] == '#')
			boungabbang[ny][nx] = temp[ny][nx];
		else
			boungabbang[ny][nx] = '#';
	}
	
}

void Solution(char c)
{
	fill(&(visited[0][0]), &(visited[0][0]) + 3 * 6, false);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (boungabbang[i][j] == c)
				Reverse(i, j);
		}
	}
}

void print()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout << boungabbang[i][j];
		}
		cout << endl;
	}
}

int main()
{
	cin >> s;

	for (int i = 0; i < s.size(); ++i)
		Solution(s[i]);
	print();
}