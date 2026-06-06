#include <iostream>
using namespace std;

int main()
{
	int arr[5]{ 1,2,3,4,5 };
	int len = 5;

	int* p = arr;
	for (int i = 0; i < len; ++i)
	{
		cout << p[i] << endl;//안전
	}

	cout << p[10] << endl;// 위험!! 메모리 침범
}
