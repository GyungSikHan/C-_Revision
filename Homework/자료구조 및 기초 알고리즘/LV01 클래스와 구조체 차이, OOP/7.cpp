#include <iostream>
using namespace std;
bool IsExist(const char* arr, const char& a, const int& len)
{
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == a)
			return true;
	}
	return false;
}

int main()
{
	char arr[5] = "MTKC";
	char a{};
	cin >> a;

	cout << (IsExist(arr, a, 5) ? "발견" : "미발견") << endl;
}