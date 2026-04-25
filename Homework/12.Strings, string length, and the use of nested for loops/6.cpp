#include <iostream>
using namespace  std;

int Length(char* arr, char c)
{
	int idx{};
	while (true)
	{
		if (arr[idx] == '\0')
			break;

		if (arr[idx] == c)
		{
			break;
		}

		idx++;
	}

	return idx;
}

int main()
{
	char arr[8]{ 'M','I','N','Q','U','E','S','\0' };
	char arr2[3]{};

	for (int i = 0; i< 3; i++)
	{
		cin >> arr2[i];
	}

	for (int i = 0; i< 3; i++)
	{
		cout << Length(arr, arr2[i]) << endl;
	}
}