#include <iostream>
using namespace std;

void RowMasking(int* arr)
{
	for (int i = 0; i < 4; ++i)
	{
		arr[i] = 1;
	}
}
void ColumnMasking(int* arr)
{
	for (int i = 0; i < 4; ++i)
	{
		*(arr + (i*4)) = 1;
	}
}

int main()
{
	int arr[4][4]{};

	for (int i = 0; i < 3; ++i)
	{
		char c{};
		int a{};
		cin >> c >> a;

		if (c == 'G')
			RowMasking(arr[a]);
		else
			ColumnMasking(&arr[0][a]);
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}