#include <iostream>
using namespace std;

const int len = 10;

int Input()
{
	int x{};
	cin >> x;

	return x;
}

int Dev(int x, int* arr)
{
	x = std::abs(x);
	int idx{};
	while (x != 0)
	{
		arr[idx++] = x % 10;
		x /= 10;
	}

	return idx;
}

void Reverse(const int* arr, int length)
{
	int idx{};
	for (int i = 0; i < length; ++i)
	{
		if (i == 0 && arr[i] == 0)
			continue;

		cout << arr[i];
	}
}

void Solution(int& x, int* ret)
{
	int arr[len]{};
	
	int length = Dev(x, arr);
	Reverse(arr, length);
}

int main()
{
	int x = Input();
	int ret[len]{};

	Solution(x, ret);
}