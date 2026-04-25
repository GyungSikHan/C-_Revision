#include <iostream>
using namespace std;

char arr[2][6]
{
	'4','5','7','1','3','2',
	'D','F','Q','W','G','Z'
};

int main()
{
	int input{};
	int x = -1;
	cin >> input;

	for (int i = 0; i < 6; i++)
	{
		if (arr[0][i] - '0' == input)
		{
			x = i;
			break;
		}
	}

	if (x != -1)
	{
		cout << arr[1][x];
	}
	else
		cout << "찾지 못함";
}