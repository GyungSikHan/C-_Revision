#include <iostream>
#include <vector>
using namespace std;

int len{};
vector<int> building{};

struct Ret
{
	int startIndex;
	int endIndex;
	int sum;
};

int main()
{
	cin >> len;
	building.resize(len, 0);

	for (int i = 0; i < len; ++i)
		cin >> building[i];

	Ret ret{0,0,-987654321};

	for (int i = 0; i < len; ++i)
	{
		int tempSum{};
		for (int j = i; j < len; ++j)
		{
			tempSum += building[j];

			if (tempSum > ret.sum)
			{
				ret.sum = tempSum;
				ret.startIndex = i;
				ret.endIndex = j;
			}
		}
	}

	cout << ret.sum << endl;
	cout << ret.startIndex << " " << ret.endIndex;
}