#include <iostream>
using namespace std;

int main()
{
	char arr[3][CHAR_MAX]{};

	int idx[3]{};
	int max = -1;
	int maxIdx{};
	
	for (int i = 0; i<3;i++)
	{
		cin >> arr[i];
		while (arr[i][idx[i]] != '\0')
		{
			idx[i]++;
		}

		if (max < idx[i])
		{
			max = idx[i];
			maxIdx = i;
		}
	}

	cout << arr[maxIdx];
}