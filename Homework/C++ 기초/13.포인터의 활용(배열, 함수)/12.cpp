#include <iostream>
using namespace std;

void Input(int * arr)
{
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}
}

void MinMax(int (*arr)[4], int* max, int* min, 
	int* y1, int* x1, int* y2, int* x2)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (arr[i][j] < (*min))
			{
				(*y2) = i;
				(*x2) = j;
				(*min) = arr[i][j];
			}
			if ((*max) < arr[i][j])
			{
				(*y1) = i;
				(*x1) = j;
				(*max) = arr[i][j];
			}
		}
	}
}

int main()
{
	int arr[4][4]
	{
		3,4,1,6,
		3,5,3,6,
		-1,-1,-1,-1,
		5,4,6,0
	};
	int max = INT_MIN, min = INT_MAX;
	int y1{}, y2{}, x1{}, x2{};
	Input(arr[2]);
	MinMax(arr, &max, &min,&y1,&x1,&y2,&x2);

	cout << "MAX=" << max << "(" << y1 << "," << x1 << ")" << endl;
	cout << "MIN=" << min << "(" << y2 << "," << x2 << ")" << endl;
}