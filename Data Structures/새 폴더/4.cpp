#include <iostream>
using namespace std;

int arr[5]{ 5,7,1,2,3 };

void test(int x)
{
	if (x == 5)
		return;

	cout << arr[x] << " ";
	test(x + 1);
	cout << arr[x] << " ";
}
int main()
{
	test(0);
}