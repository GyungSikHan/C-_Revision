#include <complex>
#include <iostream>
#include <iso646.h>
using namespace std;

struct Complex
{
	double re, im;
	Complex(double r, double i):re(r), im(i){}
	void Display()
	{
		cout << re << " + " << im << "i" << endl;
	}
	Complex operator+(Complex& other)
	{
		return Complex(re+other.re, im+other.im);
	}
};

int main()
{
	Complex a(1.2, 3.4);
	Complex b(5.6, 7.8);

	Complex c = a + b;
	c.Display();
}