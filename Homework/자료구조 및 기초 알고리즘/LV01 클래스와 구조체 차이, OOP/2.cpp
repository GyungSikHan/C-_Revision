#include <iostream>
using namespace std;

int FindCharCOunt(char str[4][4])
{
	char c1{}, c2{};
	cin >> c1 >> c2;
	int count{};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (str[i][j] == c1 || str[i][j] == c2)
				count++;
		}
	}

	return count;
}

int main()
{
	char arr[4][4]
	{
		'A','B','K','T',
		'K','F','C','F',
		'B','B','Q','Q',
		'T','P','Z','F'
	};

	cout<<FindCharCOunt(arr);
}