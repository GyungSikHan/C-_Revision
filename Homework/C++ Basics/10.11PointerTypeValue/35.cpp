#include <iostream>
using namespace std;

int main()
{
	char arr[7]{ 'A','1','1' ,'1' ,'5','A','w' };
	char c{};

	cin >> c;

	int cnt{};

	for (int i = 0; i<7; i++)
	{
		if (arr[i] == c)
			cnt++;
	}

	if (3 <= cnt)
		cout << "THREE" << endl;
	else if (cnt == 2)
		cout << "TWO" << endl;
	else if (cnt == 1)
		cout << "ONE" << endl;
	else
		cout << "NOTHING" << endl;

}