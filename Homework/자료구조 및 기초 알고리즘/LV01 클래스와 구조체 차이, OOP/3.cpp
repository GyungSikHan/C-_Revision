#include <iostream>
using namespace std;

int main()
{
	char arr[6]{};
	int idx{};
	cin >> arr>>idx;

	int temp = (int)arr[idx] - 'a';

	char arr2[10]{};
	bool bFlag{};
	for (int i = 0; i < 5; ++i)
	{
		if (i == idx)
		{
			bFlag = true;
			arr2[i] = 'A';
		} 
		else
		{
			if (bFlag)
				arr2[i] = arr[idx++];
			else
				arr2[i] = arr[i];
		}
	}

	cout << arr2;
}