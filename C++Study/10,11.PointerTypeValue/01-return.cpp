#include<iostream>

using namespace std;

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	cout << Add(3, 4) << endl;

	int a = 3;
	int b = 4;

	int ret = Add(a, b);
	cout << ret << endl;

	return 0;
}