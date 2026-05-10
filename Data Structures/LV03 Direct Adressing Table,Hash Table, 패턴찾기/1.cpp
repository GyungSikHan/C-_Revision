//Sliding Window

#include<iostream>
using namespace std;

char vect[256] = "BTABCQABC";
char pattern[4] = "ABC";

bool IsPattern(int startIdx)
{
	for (int i = 0; i < 3; ++i)
	{
		if (pattern[i] != vect[startIdx + i])
			return false;
	}

	return true;
}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		if (IsPattern(i))
		{
			cout << "Pattern Found At Index: " << i << endl;
			break;
		}
	}
}