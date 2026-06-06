#include <iostream>
using namespace std;

void Test1(int (*arr)[3] /* == arr[3][3]*/)
{
	arr[0][0] = 100;
	arr[0][1] = 100;
	arr[0][2] = 100;

	arr[1][0] = 100;
	arr[1][1] = 100;
	arr[1][2] = 100;

	arr[2][0] = 100;
	arr[2][1] = 100;
	arr[2][2] = 100;
}

//2차원 배열을 매개변수로 받는 법 2
void Test2(int* arr /*arr[3]*/)
{
	arr[0] = 100;
	arr[1] = 100;
	arr[2] = 100;
}

int main()
{
	int arr[3][3]{};
	//int** ppArr = arr // 틀림
	int (*ppArr)[3] = arr;

	//본질은 1차원 배열을 여러번 나누어 2차원 배열을 사용
	Test1(arr);

	Test2(arr[0]);//첫번째 행 
	Test2(arr[1]);//두번째 행
	Test2(arr[2]);//세번째 행
}