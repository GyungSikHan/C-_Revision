#include<iostream>

using namespace std;

int main()
{
	int arr[3][3] = {
		1,0,0,
		0,1,1,
		1,0,1
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == 0)
				cout << "@";
			else
				cout << "#";
		}
		cout << endl;
	}
}