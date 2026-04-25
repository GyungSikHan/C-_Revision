#include <iostream>
using namespace std;

void Input(int* arr, int length)
{
	for (int i = 0; i< length; i++)
	{
		cin >> arr[i];
	}
}

void Mul(int* a, int* b, int* c, int length)
{
	for (int i = 0; i < length; ++i)
	{
		c[i] = a[i] * b[i];
	}
}
void Add(int* a, int* b, int* c, int length)
{
	for (int i = 0; i < length; ++i)
	{
		c[i] = a[i] + b[i];
	}
}
int main()
{
	int A[5]{};
	int B[5]{};
	int C[5]{};

	Input(A, 5);
	Input(B, 5);
	Input(C, 5);

	int ret[5]{};
	Mul(A,B,ret, 5);
	Add(ret, C, ret, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << ret[i] << " ";
	}
}