#include <iostream>
using namespace std;

int input()
{
	int data{};
	cin >> data;

	return data;
}

int cals(int a, int b,int c)
{
	return a + b + c;
}

int main()
{
	int a{}, b{}, c{};
	a = input();
	b = input();
	c = input();

	int data = cals(a,b,c);
	cout << data << endl;
}