#include <iostream>
using namespace std;

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

bool Check(const int (*arr)[4], int y, int x)
{
	for (int i = 0; i < 8; ++i)
	{
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (nx<0||nx>=4||ny<0||ny>=5)
			continue;

		if (arr[ny][nx] == 1)
			return false;
	}
	return true;
}

int main()
{
	int arr[5][4]{};
	for (int i = 0; i < 20; ++i)
	{
		cin >> arr[i / 4][i % 4];
	}

	bool bFlag{};
	for (int i = 0; i < 20; ++i)
	{
		if (arr[i / 4][i % 4] == 1)
		{
			bFlag = Check(arr, i / 4, i % 4);
			if (!bFlag)
				break;
		}
	}
	if (!bFlag)
		cout << "불안정한 상태";
	else
		cout << "안정된 상태";
}

