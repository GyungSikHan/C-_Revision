#include <iostream>
using namespace std;

int IsCheck(const int* train, const int* team, const int idx)
{
	for (int i = 0; i < 3; ++i)
	{
		if (team[i] != train[idx + i])
			return -1;
	}

	return 1;
}

int main()
{
	int train[8]{ 3,7,6,4,2,9,1,7 };
	int team[3]{};
	for (int i = 0; i < 3; ++i)
	{
		cin >> team[i];
	}

	for (int i = 0; i < 8-3; ++i)
	{
		if (IsCheck(train,team, i))
		{
			cout << i+1 << "번~" << i + 3 << "번 칸" << endl;
			break;
		}
	}

}