#include <iostream>
using namespace std;

int dy[3]{ -1,0,1 };
int dx[3]{ 1,1,1 };

int map[3][8]{};
bool visited[3][8]{};
char start{};
int cnt{};
int arriveY = 0;
int arriveX = 7;

void DFS(int y, int x)
{
	if (x == arriveX)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (nx<0 || nx>=8 || ny<0 || ny >=3)
			continue;
		if (visited[ny][nx] == true)
			continue;

		visited[ny][nx] = true;
		DFS(ny,nx);
		visited[ny][nx] = false;
	}
}

int main()
{
	cin >> start;
	int istart = start - 'A';
	
	DFS(istart, 0);
	cout << cnt << endl;
}