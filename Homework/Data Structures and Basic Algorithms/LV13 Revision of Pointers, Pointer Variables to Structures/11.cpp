#include <iostream>
using namespace std;

bool Solve(int (*arr)[4], int y, int x)
{
	if (arr[y][x] < arr[y - 1][x])
		return true;
	return false;
}

int main()
{
	int arr[4][4]//{0,1,1,0,0,2,2,1,2,3,3,2,3,3,3,2};
	{
		0,0,0,0,
		0,1,1,0,
		2,2,3,0,
		1,3,3,1
	};
	bool bFlag{};
	for (int i = 3; i > 0; --i)
	{
		for (int j = 3; j >= 0; --j)
		{
			if (arr[i][j] == 0)
				continue;
			bFlag = Solve(arr, i, j);
			if (bFlag)
				break;
		}
		if (bFlag)
			break;
	}

	if (bFlag)
		cout << "안전하지 않은 성";
	else
		cout << "안전한 성";

}