#include<iostream>
using namespace std;

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	int a = Add<int>(1, 2);
	float b = Add<float>(1.2f, 2.2f);
	double c = Add<double>(1.23, 2.23);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}