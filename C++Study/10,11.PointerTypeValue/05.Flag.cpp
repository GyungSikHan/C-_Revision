#include <iostream>

using namespace std;

int main()
{
	int vec[7]
	{
		5,6,7,1,2,7,8
	};
	bool bFlag{};

	for (int i = 0; i < 7; i++)
	{
		if (vec[i] == 7)
		{
			bFlag = true;
			break;
		}
	}

	if (bFlag == true)
		cout << "발견" << endl;
	else
		cout << "미발견" << endl;
	return 0;
}