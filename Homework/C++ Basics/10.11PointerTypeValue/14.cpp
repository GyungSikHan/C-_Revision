#include <iostream>

using namespace std;

int sum(int a, int b)
{
	return a + b;
}

int comp(int a, int b )
{
	return a - b;
}

void print(int t1, int t2)
{
	cout << "합:" << t1 << endl;
	cout << "차:" << t2 << endl;
}
int main()
{
	int a{}, b{};
	cin >> a >> b;
	int t1 = sum(a, b);
	int t2 = comp(a, b);
	print(t1, t2);
}