#include <iostream>

using namespace std;

char arr[3][5]
{
	'D','A','C','C','D',
	'S','D','F','A','E',
	'E','E','T','J','H'
};

int CHECK(char d)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (d == arr[i][j])
			{
				return 1;
			}
		}
	}
	return 0;
}

void INPUT()
{
	char c{};
	cin >> c;

	if (CHECK(c))
		cout << "있음" << endl;
	else
		cout << "없음" << endl;
}

int main()
{
	INPUT();
}