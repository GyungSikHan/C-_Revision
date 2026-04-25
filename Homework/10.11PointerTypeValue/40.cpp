#include <iostream>
using namespace std;

char arr[3][3]
{
'a', 'b','d',
'e','w','z',
'q','v','a'
};

void Process(char c)
{
	c = c - 'A' + 'a';

	bool bFlag{};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == c)
			{
				bFlag = true;
				break;
			}
		}
	}

	if (bFlag)
		cout << "존재" << endl;
	else
		cout << "없음" << endl;
}

void input()
{
	char c{};
	cin >> c;
	Process(c);
}

int main()
{
	input();
}