#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n <= 1)
		return n;

	int left = fibonacci(n-1);
	int right = fibonacci(n - 2);

	return left + right;
}

int main()
{
	int num = fibonacci(4);
}

//level 7, level8 둘다 재귀 그림 그리기