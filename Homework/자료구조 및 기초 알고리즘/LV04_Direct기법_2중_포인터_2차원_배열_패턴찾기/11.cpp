#include <iostream>
using namespace std;

void BBQ(int* a, int* b)
{
	int max = -987654321;
	int min = 987654321;

	for (int i = 0; i < 5; ++i)
	{
		int data{};
		cin >> data;

		if (max < data)
			max = data;
		if (data < min)
			min = data;
	}

	*a = max;
	*b = min;
}

int main()
{
	int a{}, b{};
	BBQ(&a, &b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}