#include <iostream>
using namespace std;

int main()
{
	int dir[8][2]{ {-1,0},{-1,1}, {0,1},{1,1},{1,0},{1,-1}, {0,-1}, {-1,-1} };

	int y[2], x[2];
	for (int i = 0; i < 2; ++i)
	{
		cin >> y[i] >> x[i];
	}

	//일반적인 방법
	{
		char arr[4][5]
		{
			'_','_','_','_','_',
			'_','_','_','_','_',
			'_','_','_','_','_',
			'_','_','_','_','_'
		};
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				int newY = y[i]+dir[j][0];
				int newX = x[i]+dir[j][1];
		
				if (newX >= 0 && newX < 5 && newY >= 0 && newY < 4 )
				{
					arr[newY][newX] = '#';
				}
			}
		}


		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
	}

	//
	{
		int arr[6][7]
		{
			'0','0','0','0','0','0','0',
			'0','-','-','-','-','-','0',
			'0','-','-','-','-','-','0',
			'0','-','-','-','-','-','0',
			'0','-','-','-','-','-','0',
			'0','0','0','0','0','0','0'
		};

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				int newY = y[i]+1 + dir[j][0];
				int newX = x[i]+1 + dir[j][1];

				if (arr[newY][newX] == '0')
					continue;

				arr[newY][newX] = '#';

			}
		}

		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 7; ++j)
			{
				cout << (char)arr[i][j];
			}
			cout << endl;
		}
	}


}