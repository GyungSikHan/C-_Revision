#include <iostream>
using namespace std;

int arr[2][6]
{
	4,5,6,1,3,1,
	2,1,3,6,3,6
};

void Input(int* a,int *b, int* c)
{
	cin >> (*a) >> (*b) >> (*c);
}
void Process(int a,int b, int c, int* cnt1, int* cnt2, int* cnt3)
{
	for (int i = 0; i< 2; i++)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (arr[i][j] == a)
				(*cnt1)++;
			else if (arr[i][j] == b)
				(*cnt2)++;
			else if (arr[i][j] == c)
				(*cnt3)++;
		}
	}
}

void Output(int a, int b, int c, int cnt1, int cnt2, int cnt3)
{
	cout << a << "=" << cnt1 << "개" << endl;
	cout << b << "=" << cnt2 << "개" << endl;
	cout << c << "=" << cnt3 << "개" << endl;
}

int main()
{
	int a{}, b{}, c{};
	int cnt1{}, cnt2{}, cnt3{};

	Input(&a, &b, &c);
	Process(a, b, c, &cnt1, &cnt2, &cnt3);
	Output(a, b, c, cnt1, cnt2, cnt3);
}