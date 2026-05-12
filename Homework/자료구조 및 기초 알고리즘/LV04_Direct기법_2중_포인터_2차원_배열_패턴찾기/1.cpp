#include <iostream>
using namespace std;

int main()
{
	int direct[4][2]
	{
		-1,0,
		1,0,
		0,-1,
		0,1
	};
	int arr[3][3]
	{
		3,5,4,
		1,1,2,
		1,3,9
	};

	int y{}, x{};
	cin >> y >> x;

	int sum{};
	for (int i = 0; i < 4; ++i)
	{
		int nY = y + direct[i][0];
		int nX = x + direct[i][1];

		if (nX<0||nX>2 || nY<0 || nY>2)
			continue;

		sum+= arr[nY][nX];
	}

	cout << sum;
}