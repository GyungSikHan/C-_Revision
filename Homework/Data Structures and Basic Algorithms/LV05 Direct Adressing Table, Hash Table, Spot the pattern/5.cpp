#include <iostream>
using namespace std;

int main()
{
	char town[3][3]
	{
		'C','D','A',
		'B','M','Z',
		'Q','P','O'
	};
	char black[5]{};
	cin >> black;

	int ret[100]{};
	int count{};

	for (int i = 0; i < 9; ++i)
	{
		ret[town[i / 3][i % 3]]++;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (ret[black[i]])
			count++;
	}
	
	cout << count << "명";
}