#include <iostream>
using namespace std;

int vect[3][5]
{
	1,2,3,4,1,
	3,1,0,0,1,
	2,3,4,1,2
};

int pattern[3] = { 3,4,1 };

bool IsPattern(int dy, int dx)
{
	for (int i = 0; i < 3; ++i)
	{
		if (pattern[i] != vect[dy][dx + i])
			return false;
	}

	return true;
}

int main()
{
	bool ret{};

	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			ret = IsPattern(y, x);
			if (ret)
				break;
		}

		if (ret)
			break;
	}

	if (ret)
		cout << "발견" << endl;
	else
		cout << "미발견" << endl;

}