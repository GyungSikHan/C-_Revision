#include <iostream>
using namespace std;

int main()
{
	char arr1[CHAR_MAX];
	char arr2[CHAR_MAX];

	cin >> arr1 >> arr2;

	int idx1{}, idx2{};
	bool bFlag1{}, bFlag2{};
	while (!bFlag1 || !bFlag2)
	{
		if (arr1[idx1] == '\0')
			bFlag1 = true;
		else
			idx1++;
		if (arr2[idx2] == '\0')
			bFlag2 = true;
		else
			idx2++;
	}

	cout << idx1 << " " << idx2;
}