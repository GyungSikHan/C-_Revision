#include <iostream>

using namespace std;

int vect[2][5]
{
	3,2,6,2,4,
	1,4,2,6,5
};

int KFC(int target)
{
	for (int i = 0; i< 2; i++)
	{
		for (int j = 0; j< 5; j++)
		{
			if(vect[i][j] == target)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int target{};
	cin >> target;

	if (KFC(target) == 1)
		cout << "값이 존재합니다" << endl;
	else
		cout << "값이 존재하지 않습니다" << endl;
}