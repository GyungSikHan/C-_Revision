#include <iostream>
using namespace std;

int main()
{
	char arr[3][6]{ "POTIO","ABCDE","YOURE" };
	int a{}, b{};
	cin >> a >> b;

	char arr2[CHAR_MAX]{};
	int idx{};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = a; j <= b; ++j)
		{
			arr2[idx++] = arr[i][j];
		}
	}

	cout << arr2;
}