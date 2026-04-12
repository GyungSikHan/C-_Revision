#include <iostream>

using namespace std;

int main()
{
	//123
	//456
	//789
	int arr[3][3]{};
	int num = 1;
	for (int i = 0; i< 3; i++)
	{
		for (int j = 0; j< 3; j++)
		{
			arr[i][j] = num++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//741
	//852
	//963
	int arr2[3][3]{};
	int num2 = 1;
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 0; j < 3; j++)
		{
			arr2[j][i] = num2++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr2[i][j];
		}
		cout << endl;
	}
	
}