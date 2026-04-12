#include <iostream>

using namespace std;

//숫자 1개를 입력받으세요
//짝수를 입력 받았다면 아래와 같이 2차 배열에 값을 채워주세요
// 1 0 0 0
// 0 2 0 0 
// 0 0 3 0
// 0 0 4 0
//홀수를 입력 받았다면 아래와 같이 2차 배열에 값을 채워주세요
// 0 0 0 1
// 0 0 2 0 
// 0 3 0 0
// 4 0 0 0
//(1중 for문을 사용하세요)

int main()
{
	int arr[4][4]{};
	int num = 1;
	int input{};

	cin >> input;

	if (input % 2 == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			arr[i][i] = num++;
		}
	}
	else
	{
		for (int i = 3; i >= 0; i--)
		{
			arr[3 - i][i] = num++;
		}
	}

	for (int i = 0; i< 4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}