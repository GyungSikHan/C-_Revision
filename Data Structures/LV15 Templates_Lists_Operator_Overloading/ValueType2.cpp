#include<iostream>
using namespace std;

template <typename T>
constexpr T pi = T(3.14L);

int main()
{
	float f = pi<float>;
	double d = pi<double>;
	int i = pi<int>;

	cout << f << endl;
	cout << d << endl;
	cout << i << endl;
}