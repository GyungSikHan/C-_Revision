#include <iostream>
using namespace std;

int main()
{
	int input{};
	cin >> input;

	int a{}, b{}, c{}, d{};
	int arr[4]{};
	int data = 10;

	int idx{};
	
	for (int i = 3; i >= 0; i--)
	{
		arr[i] = input % data;
		input /= data;
	}

	for (int i = 0; i< 4; i++)
	{
		cout << arr[i] << endl;
	}

	{
		//d = input % data;
		//input /= 10;
		//c = input % data;
		//input /= 10;
		//b = input % data;
		//input /= 10;
		//a = input % data;
	}

	//배열로 반복문 사용해서도 풀어보기
	//숙제 이후 뉴튼 수학같이 문제 푸는 수학이 아닌 읽는 수학책(세상에서 왜 필요한지)을 보면 좋다
}