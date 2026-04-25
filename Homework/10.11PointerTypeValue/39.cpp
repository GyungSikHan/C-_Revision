#include <iostream>
using namespace std;

int main()
{
	char arr[3][3]
	{
		'a','b','E',
		'E','2','W',
		'3','2','4'
	};

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			char temp{};
			if ('a' <= arr[i][j] && arr[i][j] <= 'z')
			{
				temp = arr[i][j] - 'a' + 'A';
			}
			else if ('A' <= arr[i][j] && arr[i][j] <= 'Z')
			{
				temp = arr[i][j] - 'A' + 'a';
			}
			else
			{
				temp = arr[i][j] + 5;
			}
			cout << temp << " ";
		}
		cout << endl;
	}
}