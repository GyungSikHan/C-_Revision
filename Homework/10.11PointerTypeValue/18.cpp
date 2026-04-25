#include <iostream>

using namespace std;

int main()
{
	int arr[7]{ 3,4,1,3,2,7,3 };
	int input{};
	bool bFlag{};

	cin >> input;

	for (int i = 0; i < 7; i++)
	{
		if (arr[i] == input)
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