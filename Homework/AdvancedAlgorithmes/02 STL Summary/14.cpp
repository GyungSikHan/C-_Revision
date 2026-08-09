#include <iostream>

using namespace std;

const int MAX = 987654321;
const int MIN = -987654321;

int n{};
int d{};
string s{};

int main()
{
	cin >> n;

	int up = MIN;
	int down= MAX;
	int bFlag{};

	for (int i = 0; i < n; ++i)
	{
		cin >> d >> s;
		
		if (s == "DOWN")
		{
			down = min(down, d);
		}
		else
		{
			up = max(up, d);
		}

		if (down < up)
		{
			bFlag = 1;
			break;
		}
		if (down - up == 2)
		{
			bFlag = 2;
			break;
		}

	}

	if (bFlag == 0)
		cout << up+1 << " ~ " << down-1;
	else if (bFlag == 1)
		cout << "ERROR";
	else
		cout << up + 1;
}