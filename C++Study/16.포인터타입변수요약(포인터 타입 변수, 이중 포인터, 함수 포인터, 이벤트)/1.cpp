#include <iostream>
using namespace std;

void Test()
{
	cout << "Test Function Call" << endl;
}

void Test(int a)
{
	cout << "Test Function Call "<< a << endl;
}

int Test(int a, int b)
{
	return a + b;
}

int main()
{
	void (*MyFunc)() = Test;
	MyFunc();

	void (*MyFunc2)(int) = Test;
	MyFunc2(2);

	int (*MyFunc3)(int, int) = Test;
	cout << MyFunc3(3, 4) << endl;
}