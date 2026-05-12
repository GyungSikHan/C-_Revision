#include <iostream>
using namespace std;

struct sketchbook
{
	char image[3][3];
};

int main()
{
	sketchbook sketch;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> sketch.image[i][j];
		}
	}

	int ret[100]{};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			ret[sketch.image[i][j]]++;
		}
	}

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		if (ret[i] != 0)
			cout << (char)i;
	}

}