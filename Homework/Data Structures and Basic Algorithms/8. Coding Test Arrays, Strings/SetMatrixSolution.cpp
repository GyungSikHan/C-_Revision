#include <iostream>
#include <vector>

using namespace std;

const int y = 201;
const int x = 201;

const int dy[4]{ -1,0,1,0 };
const int dx[4]{ 0,1,0,-1 };

int matrix[y][x]{};

struct Point
{
	int mY;
	int mX;
};

void Zeroes(const int n, const int m, const Point& pos)
{
	for (int i = 0; i < m; ++i)
		matrix[pos.mY][i] = 0;
	for (int i = 0; i < n; ++i)
		matrix[i][pos.mX] = 0;
	
}

void Print(const int n, const int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n{}, m{};
	cin >> n >> m;

	vector<Point> v;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 0)
				v.push_back({ (int)i,(int)j });
		}
	}

	for (const Point& iter : v)
		Zeroes(n, m, iter);
	Print(n,m);
}