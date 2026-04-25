#include <iostream>

using namespace std;

int main()
{
	char str[8]{};

	for (int i = 0; i < 8; i++)
		cin >> str[i];

	char big[8]{}, small[8]{};

	int idx{}, idx2{};
	for (int i = 0; i< 8; i++)
	{
		if ('A'<=str[i] && str[i] <= 'Z')
			big[idx++] = str[i];
		else
			small[idx2++] = str[i];
	}

	cout << "big=" << big << endl;
	cout << "small=" << small << endl;
}