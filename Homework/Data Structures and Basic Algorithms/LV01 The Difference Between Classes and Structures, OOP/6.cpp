#include <iostream>
using namespace std;
bool IsExist(const char* str, int length, const char* search)
{
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == *search)
			return true;
	}

	return false;
}

int main()
{
	char m = 'M';
	char a[3][11]{};
	for (int i = 0; i < 3; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 3; ++i)
	{
		cout << (IsExist(a[i], 10, &m) ? "M이 존재합니다" : "M이 존재하지 않습니다" ) << endl;
	}
}