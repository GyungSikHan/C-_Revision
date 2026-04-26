#include <iostream>
using namespace std;

int main()
{
	int arr[4][4]
	{
		2, 10 ,18 ,26,
		4, 12 ,20 ,28,
		6, 14, 22 ,30,
		8 ,16, 24 ,32

	};

	for (int i =0;i<4;i++)
	{
		for (int j = 0;j<4;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}