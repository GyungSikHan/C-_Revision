#include<iostream>
using namespace std;

template<typename T>
void Swap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<>
void Swap(double& a, double& b)
{
	cout << "double은 교환하지 않음" << endl;
}
int main()
{
	int a = 20, b = 30;
	Swap(a, b);
	cout << a << " " << b << endl;

	double c = 3.4, d = 2.2;
	Swap(c, d);
	cout << c << " " << d << endl;
}