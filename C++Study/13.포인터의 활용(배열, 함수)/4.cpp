#include <iostream>
using namespace std;

void Increase(int* p, const int& length)
{
	for (int i = 0; i < length; ++i)
	{
		p[i]++;
	}
}

int main()
{
	int arr[7]{ 123,42,2,66,7, 9 ,10 };
	Increase(arr, 7);

	for (int i = 0; i < 7; ++i)
	{
		cout << arr[i] << endl;
	}
}