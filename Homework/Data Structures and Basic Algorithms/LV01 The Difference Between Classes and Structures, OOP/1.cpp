#include <iostream>
using namespace std;



int main()
{
	char arr[3][10]{};

	for (int i = 0; i < 3; ++i)
	{
		cin >> arr[i];
	}

	char ret[10]{};
	int idx{};

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (arr[i][j] == '\0')
			{
				ret[idx++] += arr[i][j - 1];
				break;
			}
		}
	}

	cout << ret << endl;
}