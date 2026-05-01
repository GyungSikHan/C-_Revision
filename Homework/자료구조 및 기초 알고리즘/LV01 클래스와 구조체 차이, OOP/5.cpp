#include <iostream>
using namespace std;

int main()
{
	char arr[CHAR_MAX]{};
	cin >> arr;
	int idx{};
	cin >> idx;

	char ret[CHAR_MAX]{};
	int idx2{};
	for (int i = 0; i < CHAR_MAX; ++i)
	{
		if (arr[i] == '\0')
			break;
		else if (i != idx)
		{
			ret[idx2++] = arr[i];
		}
	}

	cout << ret;
}