#include <iostream>
using namespace std;

void DAT(const char* vect, int* ret)
{
	for (int i = 0; i < 6; ++i)
	{
		ret[vect[i]]++;
	}
}

void CheckResult(const int* ret, const char* str, const int n, char* result)
{
	for (int i = 0; i < n; ++i)
	{
		if (ret[str[i]])
		{
			result[i] = 'O';
		}
		else
			result[i] = 'X';
	}
}

int main()
{
	char vect[7] = "CODING";
	int ret[100]{};
	int n{};
	char str[256]{};

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> str[i];
	
	DAT(vect, ret);
	char result[100]{};
	CheckResult(ret, str, n, result);
	
	cout << result;
}