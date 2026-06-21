#include <iostream>
using namespace std;

struct Point
{
	int y;
	int x;
};

int main()
{
	int arr[5][5]{};
	bool bFlag{};
	for (int i = 0; i < 6; ++i)
	{
		Point p{};
		cin >> p.y >> p.x;

		if (arr[p.y][p.x])
			bFlag = true;
		else
			arr[p.y][p.x] = 1;
	}

	cout << (bFlag ? "중복된좌표발견" : "중복없음") << endl;
}