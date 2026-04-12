#include <iostream>

using namespace std;

void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	{

		int num = 0;
		void* p = &num;

		int* num2 = 200;
		int& p2 = &num2;

		char ch = 'A';
		char* pC = &ch;

		int arr[10]{};
		int* p3 = arr; // or &arr[0]


	}
	/////////////////////////////////////////

	//Call By Value
	{
		int num1 = 100;
		int num2 = 200;

		Swap(num1, num2);
	}
	//Call By Reference
	{
		int num1 = 100;
		int num2 = 200;
		Swap(&num1, &num2);
	}
	return 0;
}