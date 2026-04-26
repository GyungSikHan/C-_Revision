#include <iostream>
using namespace std;

char arr[4][3]
{
	'D','A','D',
	'Q','W','Q',
	'A','S','D',
	'A','S','D'
};

void Find(char c)
{
	bool bFlag{};
	for (int i = 0; i< 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == c)
			{
				bFlag = true;
				break;
			}
		}
		if (bFlag )
			break;
	}

	if (bFlag)
		cout << "존재" << endl;
	else
		cout << "없음" << endl;
}

int main()
{
	char c{};

	cin >> c;
	Find(c);
}