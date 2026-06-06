#include <iostream>
using namespace std;

int main()
{
	int a[4]{}, b[4]{};
	for (int i = 0; i < 4; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> b[i];
	}

	int ret[4]{};
	int idx = 3;
	for (int i = 0; i < 4; ++i)
	{
		ret[i] = a[i] + b[idx--];
	}

	for (int i = 0; i < 4; ++i)
	{
		cout << ret[i] << " ";
	}
}