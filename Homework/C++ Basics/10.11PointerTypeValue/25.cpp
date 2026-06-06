#include <iostream>

using namespace std;

int main()
{
	int arr[5][5]
	{
		21, 16, 11, 6 ,1,
		22, 17, 12, 7 ,2,
		23, 18, 13, 8 ,3,
		24, 19, 14, 9 ,4,
		25, 20, 15, 10, 5
	};

	int input{};

	cin >> input;

	for (int i = 0; i< 5; i++)
	{
		arr[input][i] = input;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout << endl;
	}
}