#include <iostream>
using namespace std;

void Test(int* arr /*int arr[10]*/)
{
	*(arr) = 100;    // == arr[0] = 100과 동일
	*(arr + 1) = 100;// == arr[1] = 100과 동일
	*(arr + 2) = 100;
	*(arr + 3) = 100;
	*(arr + 4) = 100;
	*(arr + 5) = 100;
	*(arr + 6) = 100;
	*(arr + 7) = 100;
	*(arr + 8) = 100;
	*(arr + 9) = 100;

	//배열 표기법과 동일하게 사용 가능
	arr[0] = 200;
	arr[1] = 200;
	arr[2] = 200;
	arr[3] = 200;
	arr[4] = 200;
	arr[5] = 200;
	arr[6] = 200;
	arr[7] = 200;
	arr[8] = 200;
	arr[9] = 200;
}

int main()
{
	int vec[10]{};

	Test(vec/*&vec[0]*/);
}