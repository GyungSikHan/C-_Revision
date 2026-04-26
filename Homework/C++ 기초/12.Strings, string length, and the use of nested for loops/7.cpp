#include <iostream>
using namespace std;

int main()
{
	char arr[CHAR_MAX];
	char c;


	cin >> arr;

	for (int i = 0; i< 3; i++)
	{
		int idx{};
		int cnt{};
		cin >> c;

		while (arr[idx] != '\0')
		{
			if (arr[idx] == c)
				cnt++;
			idx++;
		}

		cout << c << "=" << cnt << endl;
	}

}