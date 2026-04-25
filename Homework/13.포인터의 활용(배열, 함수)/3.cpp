#include <iostream>
using namespace std;

void StringLen(char* arr, int* length)
{
	for (int i = 0; i < CHAR_MAX; ++i)
	{
		if (arr[i] == '\0')
			break;

		(*length)++;
	}
}

int main()
{
	char arr[CHAR_MAX]{};
	cin >> arr;

	int length{};

	StringLen(arr, &length);

	cout << length << "글자" << endl;
}