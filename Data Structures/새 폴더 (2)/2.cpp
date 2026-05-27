#include <iostream>
using namespace std;

void Print(int* arr)
{
	for (int i = 0; i < 4; ++i)
	{
		cout << arr[i];
	}
	cout << endl;
}

void Solve(int day, int* arr, int n)
{
	if (day ==4)
	{
		Print(arr);
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		arr[day] = i;
		Solve(day + 1,  arr, n);
	}
}

int main()
{
	int n{};
	int arr[4]{};
	cin >> n;

	Solve(0, arr, n);
}