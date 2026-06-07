#include <iostream>
using namespace std;

int main()
{
	char arr[5][3]
	{
		'A','B','C',
		'A','G','H',
		'H','I','J',
		'K','A','B',
		'A','B','C',
	};

	char ret[256]{};

	for (int i = 0; i < 15; ++i)
	{
		ret[arr[i / 3][i % 3]]++;
	}

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		for (int j = 0; j < ret[i]; ++j)
		{
			cout << (char)i;
		}
	}
}