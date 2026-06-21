#include<iostream>
#include <string>
using namespace std;

void CopyChar(char* arr, const char* str)
{
	strcpy_s(arr, sizeof(arr), str);
}

int main()
{
	char str[256]{};
	cin >> str;
	char arr[3][256]{};
	int idx{};
	int sub{};
	for (int i = 0; i < strlen(str); ++i)
	{
		if (i/5 == 1)
		{
			idx = 1;
			sub = 5;
		}
		else if (i / 5 == 2)
		{
			idx = 2;
			sub = 10;
		}
		arr[idx][i-sub] = str[i];
	}

	for (int i = 0; i < 3; ++i)
		cout << arr[i] << endl;
}