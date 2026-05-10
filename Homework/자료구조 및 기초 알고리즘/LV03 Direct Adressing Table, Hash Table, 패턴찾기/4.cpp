#include <iostream>
using namespace std;

int main()
{
	char arr[9]{};
	cin >> arr;

	int ret[100]{};
	for (int i = 0; i < 9; ++i)
	{
		if (arr[i] == '\0')
			break;
		ret[arr[i]]++;
	}

	int max = ret[0];
	char c;
	for (int i = 'A'; i <= 'Z'; ++i)
	{
		if (max < ret[i])
		{
			max = ret[i];
			c = (char)i;
		}
	}

	cout << c;
}