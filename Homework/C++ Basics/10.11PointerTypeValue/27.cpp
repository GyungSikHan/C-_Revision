#include <iostream>
using namespace std;

int main()
{
	int arr[3]{};
	int arr2[3][4]{};

	cin >> arr[0] >> arr[1] >> arr[2];

	for (int i = 0; i< 3; i++)
	{
		for (int j = 0; j< 4; j++)
		{
			arr2[i][j] = arr[i] + j;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
}