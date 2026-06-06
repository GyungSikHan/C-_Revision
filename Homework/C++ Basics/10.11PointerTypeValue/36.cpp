#include <iostream>

using namespace std;

int main()
{
	char arr[3][5]
	{
		'a','b','a','c','z',
		'c','t','a','c','d',
		'c','c','c','c','a'
	};

	char c{};
	cin >> c;

	int cnt{};

	for (int i =0; i<3; i++)
	{
		for (int j = 0; j< 5; j++)
		{
			if (arr[i][j] == c)
				cnt++;
		}
	}

	if (7 <= cnt)
		cout << "세상에" << endl;
	else if (5 <= cnt)
		cout << "와우" << endl;
	else if (3 <= cnt)
		cout << "이야" << endl;
	else
		cout << "이런" << endl;
}