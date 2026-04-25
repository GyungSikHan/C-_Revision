#include <iostream>

using namespace std;

int main()
{
	char arr[2][3]{};
	char c[6];

	for (int i = 0; i < 6; i++)
		cin >> c[i];

	int cnt{};
	for (int i = 0; i< 2; i++)
	{
		for (int j = 0; j< 3; j++)
		{
			if (c[cnt] == '0')
				arr[i][j] = '#';
			else
				arr[i][j] = c[cnt];
			cnt++;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<arr[i][j] ;
		}
		cout << endl;
	}
}