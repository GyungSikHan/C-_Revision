#include <iostream>
using namespace std;

int arr[3][3]
{
	1,1,1,
	1,2,1,
	3,6,3
};

int Count(int x)
{
	int cnt{};
	for (int i = 0; i< 3; i++)
	{
		for (int j = 0; j< 3; j++)
		{
			if (x == arr[i][j])
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	int input{};
	cin >> input;

	cout << Count(input);
}