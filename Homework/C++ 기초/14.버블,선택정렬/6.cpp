#include <iostream>
using namespace std;

int main()
{
	char arr[3][CHAR_MAX] = { "BBQWORLD", "KFCAPPLE","LOT" };
	char input{};
	cin >> input;

	int cnt{};
	for (int i = 0; i < 3; i++)
	{
		int idx{};
		while (arr[i][idx] != '\0')
		{
			if (arr[i][idx] == input)
				cnt++;
			idx++;
		}
	}

	cout << cnt;

}