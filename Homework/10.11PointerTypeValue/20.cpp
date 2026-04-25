#include <iostream>

using namespace std;

int main()
{
	char str[14] = "StructPointer";
	char c{};
	bool bFlag{};
	cin >> c;

	for (int i = 0; i< 14;i++)
	{
		if (str[i] == c)
		{
			bFlag = true;
			break;
		}
	}
	if (bFlag)
		cout << "발견" << endl;
	else
		cout << "미발견" << endl;
}