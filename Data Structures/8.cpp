#include <iostream>
using namespace std;

bool IsSame(char* strA, char* strB)
{
	for (int i = 0; i < 256; ++i)
	{
		if (strA[i] != strB[i])
			return false;
	}

	return true;
}

int main()
{
	char strA[256] = "ABCD";
	char strB[256] = "ABCE";

	bool checkK = IsSame(strA, strB);

	if (checkK)
		cout << "Same" << endl;
	else
		cout << "Differnt" << endl;
}