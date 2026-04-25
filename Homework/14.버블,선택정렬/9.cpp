#include <iostream>
using namespace std;

int main()
{
	char arr[4][6]{};
	bool bFlag[2]{};

	for (int i = 0; i < 4; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (arr[i][j] == 'A')
				bFlag[0] = true;
			if (arr[i][j] == 'B')
				bFlag[1] = true;
		}
	}

	if (bFlag[0] == true && bFlag[1] == true)
		cout << "대발견";
	else if (bFlag[0] == true || bFlag[1] == true)
		cout << "중발견";
	else
		cout << "미발견" << endl;
}