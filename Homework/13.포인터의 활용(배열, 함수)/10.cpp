#include <iostream>
using namespace std;

void Input(char* a, char* b)
{
	cin >> (*a) >> (*b);
}

void Processing(int* arr, char a, char b, int* sum)
{
	int min = a - 'A';
	int max = b - 'A';

	if (max < min)
	{
		int temp = max;
		max = min;
		min = temp;
	}

	for (int i = min + 1; i < max; i++)
		(*sum) += arr[i];
}

int main()
{
	int arr[7]{ 4,2,5,1,6,7,3 };
	char a{}, b{};
	int sum{};

	Input(&a, &b);
	Processing(arr, a, b, &sum);
	cout << sum;
}