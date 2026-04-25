#include <iostream>
using namespace std;

void CountLine(char (*arr)[10])
{
	for (int i = 0; i < 3; ++i)
	{
		int idx{};
		while (arr[i][idx] != '\0')
		{
			idx++;
		}

		cout << idx << "=" << arr[i]  << endl;
	}
}

int main()
{
	char arr[3][10]{};
	for (int i = 0; i < 3; ++i)
	{
		cin >> arr[i];
	}
	CountLine(arr);
}