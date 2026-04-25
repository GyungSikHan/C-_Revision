#include <iostream>
using namespace std;

int main()
{
	char arr[6]{'D','F','G','D','A','Q'};
	char a{}, b{};
	bool bFlag{};
	cin >> a >> b;

	for (int i = 0; i< 6; i++)
	{
		if (a <= arr[i] && arr[i] <= b)
		{
			bFlag = true;
			break;
		}
	}

	if (bFlag)
		cout << "발견!!!" << endl;
	else
		cout << "미발견!!!" << endl;
}