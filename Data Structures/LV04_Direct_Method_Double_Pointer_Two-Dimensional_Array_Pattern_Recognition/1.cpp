//Direct 기법
#include <iostream>
using namespace std;

int main()
{
	int arr[3][3]
	{
		1,2,3,
		4,5,6,
		7,8,9
	};

	int direct[4][2]
	{
		-1,0,
		1,0,
		0,-1,
		0,1
	};
	int y = 1, x = 1;
	int sum{};

	for (int i = 0; i < 4; ++i)
	{
		int newY = y + direct[i][0];
		int newX = y + direct[i][1];

		if (newX >= 0 && newX <= 2 && newY >= 0 && newY <= 2)
			sum += arr[newY][newX];
	}

	cout << sum << endl;
}