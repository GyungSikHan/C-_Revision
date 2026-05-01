#include <iostream>
using namespace std;
int IsExist(const char (*arr)[4], const char& a, const char& b)
{
	int count{};
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (arr[i][j] == a || arr[i][j] == b)
			{
				count++;
			}
		}
	}

	return count;
}

int main()
{
	char arr[2][4]
	{
		{"GKT"}, {"PAC"}
	};
	char a{}, b{};
	cin >> a >> b;

	int ret = IsExist(arr, a, b);
	if (ret == 0)
		cout << "미발견";
	else if (ret == 1)
		cout << "중발견";
	else
		cout << "대발견";
}