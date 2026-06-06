#include <iostream>
using namespace std;

int main()
{
	int num[6]{};

	for (int i = 0; i < 6; ++i)
	{
		cin >> num[i];
	}

	for (int i = 1; i < 6; ++i)
	{
		num[i] = num[i - 1] + num[i];
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << num[i] << " ";
	}
}