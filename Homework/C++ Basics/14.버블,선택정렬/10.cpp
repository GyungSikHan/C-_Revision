#include <iostream>
using namespace std;

int main()
{
	char arr1[2][6]{};
	char arr2[12]{};

	for (int i = 0; i < 2; ++i)
	{
		cin >> arr1[i];
	}

	int idx{};
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (arr1[i][j] == '\0')
				break;
			arr2[idx++] = arr1[i][j];
		}
	}

	cout << arr2;
}