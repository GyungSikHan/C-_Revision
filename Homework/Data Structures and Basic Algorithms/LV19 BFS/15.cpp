#include <iostream>
using namespace std;

int cogwheel[3][4]
{
	3,2,5,3,
	7,6,1,6,
	4,9,2,7
};

void Rotation(int cnt, int x)
{
	int count{};
	while (count != cnt)
	{
		int temp = cogwheel[2][x];
		for (int i = 2; i > 0; --i)
		{
			cogwheel[i][x] = cogwheel[i-1][x];
		}
		cogwheel[0][x] = temp;

		count++;
	}
}

void Print()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << cogwheel[i][j];
		}
		cout << endl;
	}
}
int main()
{
	int n{};

	for (int i = 0; i < 4; ++i)
	{
		cin >> n;
		Rotation(n, i);
	}
	Print();
}