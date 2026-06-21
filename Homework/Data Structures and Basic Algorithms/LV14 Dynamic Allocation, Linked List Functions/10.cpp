#include <iostream>
using namespace std;

bool Matching(const char* str)
{
	if (str[0] == 'F')
		return false;
	int count = 1;
	for (int i = 1; i < strlen(str); ++i)
	{
		if (str[i] == 'B')
			count++;
		else
			count--;
	}

	if (count == 0)
		return true;
	return false;
}

int main()
{
	char str[11]{};
	cin>>str;
	cout << (Matching(str) ? "짝이맞음" : "짝이안맞음" )<< endl;
}